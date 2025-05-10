#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
    String();
    String(const char *pstr);
    String(const String &rhs);
    String &operator=(const String &rhs);
    
private:
    class CharProxy
    {
    public:
        CharProxy(String &self, size_t idx);
        //CharProxy(String self, size_t idx); //String &self vs String self
        char &operator=(const char &ch);
        friend ostream &operator<<(ostream &os, const CharProxy &);
    private:
        String &_self;
        size_t _idx;
    };
    void initRefCount()
    {
        *(int *)(_pstr - 4)  = 1;
    }

    void increaseRefCount()
    {
        ++ *(int *)(_pstr - 4);
    }

    void decreaseRefCount()
    {
        -- *(int *)(_pstr - 4);
    }

    void release()
    {
        decreaseRefCount();
        if(0 == getRefCount())
        {
            delete [](_pstr - 4);
            _pstr = nullptr;
        }
    }

    size_t size() const
    {
        return strlen(_pstr);
    }
public:

    int getRefCount() const
    {
        return *(int *)(_pstr - 4);
    }

    const char *c_str() const
    {
        return _pstr;
    }

    CharProxy operator[](size_t idx)
    {
        return CharProxy(*this, idx);
    }

    friend ostream &operator<<(ostream &os, const String &rhs);
    friend ostream &operator<<(ostream &os, const CharProxy &rhs);

private:
    char *_pstr;
};


String::String()
: _pstr(new char[5]() + 4)
{
    cout << "String()" << endl;
    initRefCount();
}

String::String(const String &rhs)
: _pstr(rhs._pstr)
{
    cout << "String(const String &)" << endl;
    increaseRefCount();
}

String::String(const char *pstr)
: _pstr(new char[strlen(pstr) + 5]() + 4)
{
    cout << "String(const char *)" << endl;
    strcpy(_pstr, pstr);
    initRefCount();
}

String::CharProxy::CharProxy(String &self, size_t idx)
: _self(self)
, _idx(idx)
{
    //cout << "CharProxy(String, size_t)" << endl;
}

char &String::CharProxy::operator=(const char &ch)
{
    if(_idx < _self.size())
    {
        if(_self.getRefCount() > 1)
        {
            char *ptmp = new char[_self.size() + 5]() + 4;
            strcpy(ptmp, _self._pstr);
            _self.decreaseRefCount();
            _self._pstr = ptmp;
            _self.initRefCount();
        }
        _self._pstr[_idx] = ch;
        return _self._pstr[_idx];
    }
    else
    {
        static char nullchar = '\0';
        return nullchar;
    }
}

ostream &operator<<(ostream &os, const String &rhs)
{
    if(rhs._pstr)
    {
        os << rhs._pstr;
    }
    return os;
}

ostream &operator<<(ostream &os, const String::CharProxy &rhs)
{
    if(rhs._idx < rhs._self.size())
    {
        os << rhs._self._pstr[rhs._idx];
    }
    return os;
}

String &String::operator=(const String &rhs)
{
    cout << "String &operator=(const String &)" << endl;
    if(this != &rhs) //四步
    {
        release();
        _pstr = rhs._pstr;
        increaseRefCount();
    }
    return *this;
}

void test()
{
    String s1("hello");
    String s2 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    printf("&s1 = %p\n", s1.c_str());
    printf("&s2 = %p\n", s2.c_str());
    cout << "s1.getRefCount() = " << s1.getRefCount() << endl;
    cout << "s2.getRefCount() = " << s2.getRefCount() << endl;
    

    cout << endl;
    String s3("world");
    cout << "s3 = " << s3 << endl;
    printf("&s3 = %p\n", s3.c_str());
    cout << "s3.getRefCount() = " << s3.getRefCount() << endl;

    cout << endl;
    s3 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("&s1 = %p\n", s1.c_str());
    printf("&s2 = %p\n", s2.c_str());
    printf("&s3 = %p\n", s3.c_str());
    cout << "s1.getRefCount() = " << s1.getRefCount() << endl;
    cout << "s2.getRefCount() = " << s2.getRefCount() << endl;
    cout << "s3.getRefCount() = " << s3.getRefCount() << endl;

    cout << endl << "对s3[0]进行写操作" << endl;
    //before CharProxy(String self, size_t idx);
    //after CharProxy(String &self, size_t idx);
    //如果不加引用符号 传参过程会是这样：
    //1、String self = *this 执行一次拷贝构造函数 
    //2、String &_self = self;
    //所以实际上对_self._pstr的修改没有传递到*this,对于下面一条语句来说就是s3的内容并没有修改
    //这里的String self只是构造函数参数列表里面的一个临时对象，它的生命周期只在构造函数内，
    //执行完构造函数后就会销毁，这样就会报错 sementation fault
    s3.operator[](0).operator=('H');
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("&s1 = %p\n", s1.c_str());
    printf("&s2 = %p\n", s2.c_str());
    printf("&s3 = %p\n", s3.c_str());
    cout << "s1.getRefCount() = " << s1.getRefCount() << endl;
    cout << "s2.getRefCount() = " << s2.getRefCount() << endl;
    cout << "s3.getRefCount() = " << s3.getRefCount() << endl;

    cout << endl << "对s1[0]执行读操作" << endl;
    cout << "s1[0] = " << s1[0] << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("&s1 = %p\n", s1.c_str());
    printf("&s2 = %p\n", s2.c_str());
    printf("&s3 = %p\n", s3.c_str());
    cout << "s1.getRefCount() = " << s1.getRefCount() << endl;
    cout << "s2.getRefCount() = " << s2.getRefCount() << endl;
    cout << "s3.getRefCount() = " << s3.getRefCount() << endl;
}

int main()
{
    test();
    return 0;
}

