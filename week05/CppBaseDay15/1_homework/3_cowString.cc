#include <iostream>
#include <string.h>
using namespace std;

class String
{
private:
    class CharProxy
    {
    public:
        CharProxy(String &self, size_t idx); //加上引用，确保参数传递
        char &operator=(const char &ch); //善用引用
        //如果没有重载输出流运算符，但是写了类型转换函数，那么在适当的时候会调用类型转换函数
        //类型转换函数
        operator char()
        {
            return _self._pstr[_idx];
        }
    private:
        String &_self;
        size_t _idx;
    };
public:
    String();
    String(const char *pstr);
    String(const String &rhs);
    String &operator=(const String &rhs);
    CharProxy operator[](size_t idx);
    ~String();
private:
    void release();
    void initRefCount();
    void increaseRefCount();
    void decreaseRefCount();
    size_t size() const;
public:
    const char *c_str() const;
    int getRefCount() const;
    friend ostream &operator<<(ostream &os, const String &rhs);

private:
    char *_pstr; //指向底层字符数组的指针
};

String::String()
: _pstr(new char[5]() + 4)
{
    cout << "String()" << endl;
    initRefCount();
}

String::String(const char *pstr)
: _pstr(new char[strlen(pstr) + 5]() + 4)
{
    cout << "String(const char *)" << endl;
    strcpy(_pstr,pstr);
    initRefCount();
}

String::String(const String &rhs)
: _pstr(rhs._pstr)
{
    cout << "String(const String &)" << endl;
    increaseRefCount();
}
#if 0
String &String::operator=(const String &rhs)
{
    cout << "String &operator=(const String &)" << endl;
    if(_pstr != rhs._pstr) //判断是否是自复制
    {
        if(getRefCount() > 1) 
        {
            char *ptmp = new char[strlen(_pstr) + 5]() + 4;
            strcpy(ptmp, _pstr);
            decreaseRefCount();
            _pstr = ptmp;
            initRefCount();
        }
    }
    return *this;
}
#endif

String &String::operator=(const String &rhs)
{
    cout << "String &operator=(const String &rhs)" << endl;
    if(this != &rhs) //if(_pstr != rhs._pstr)
    {
        release();
        _pstr = rhs._pstr;
        increaseRefCount();
    }
    return *this;
}

String::CharProxy String::operator[](size_t idx)
{
    return CharProxy(*this, idx);
}

String::~String()
{
    cout << "~String()" << endl;
    release();
}

void String::release()
{
    decreaseRefCount();
    if(0 == getRefCount())
    {
        delete [](_pstr - 4);
        //_pstr = nullptr;
    }
}

void String::initRefCount()
{
    *(int *)(_pstr - 4) = 1;
}

void String::increaseRefCount()
{
    ++ *(int *)(_pstr - 4);
}

void String::decreaseRefCount()
{
    -- *(int *)(_pstr - 4);
}

size_t String::size() const
{
    return strlen(_pstr);
}

String::CharProxy::CharProxy(String &self, size_t idx)
: _self(self) //String &_self = self;
, _idx(idx)
{
}
#if 1
char &String::CharProxy::operator=(const char &ch) //写操作
{
    if(_idx < _self.size())
    {
        if(_self.getRefCount() > 1)
        {
            char *ptmp = new char[strlen(_self._pstr) + 5]() + 4;
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
#endif


const char *String::c_str() const
{
    return _pstr;
}

int String::getRefCount() const
{
    return *(int *)(_pstr - 4);
}

ostream &operator<<(ostream &os, const String &rhs)
{
    if(rhs._pstr)
    {
        os << rhs._pstr;
    }
    return os;
}

void test()
{
    String s1("hello");
    String s2 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    printf("&s1 = %p\n",s1.c_str());
    printf("&s2 = %p\n",s2.c_str());
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
    printf("&s1 = %p\n",s1.c_str());
    printf("&s2 = %p\n",s2.c_str());
    printf("&s3 = %p\n", s3.c_str());
    cout << "s1.getRefCount() = " << s1.getRefCount() << endl;
    cout << "s2.getRefCount() = " << s2.getRefCount() << endl;
    cout << "s3.getRefCount() = " << s3.getRefCount() << endl;

    cout << endl;
    cout << "对s3[0]进行写操作" << endl;
    s3[0] = 'H';
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("&s1 = %p\n",s1.c_str());
    printf("&s2 = %p\n",s2.c_str());
    printf("&s3 = %p\n", s3.c_str());
    cout << "s1.getRefCount() = " << s1.getRefCount() << endl;
    cout << "s2.getRefCount() = " << s2.getRefCount() << endl;
    cout << "s3.getRefCount() = " << s3.getRefCount() << endl;

    cout << endl;
    cout << "对s1[0]进行读操作" << endl;
    cout << "s1[0] = " << s1[0] << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("&s1 = %p\n",s1.c_str());
    printf("&s2 = %p\n",s2.c_str());
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

