#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::ostream;

//写时复制：浅拷贝+引用计数

class String
{
public:
    String(); //默认构造函数
    String(const char *pstr); //字符串常量初始化
    String(const String &rhs); //拷贝构造函数
    String &operator=(const String &rhs); //赋值运算符重载
    char &operator[](size_t idx); //下标访问运算符重载
    ~String();
    const char *c_str() const; //c++风格字符串--->c风格字符数组
    int getRefCount(); //获取引用计数
    size_t size() const; //获取字符串长度
    friend ostream &operator<<(ostream &os, const String &rhs); //输出流运算符重载
private:
    char *_pstr;
};

String::String()
: _pstr(new char[5]() + 4)
{
    cout << "String()" << endl;
    *(int *)(_pstr - 4) = 1;
}

String::String(const char *pstr)
: _pstr(new char[strlen(pstr) + 5]() + 4)
{
    cout << "String(const char *)" << endl;
    strcpy(_pstr, pstr);
    *(int *)(_pstr - 4) = 1;
}

String::String(const String &rhs)
: _pstr(rhs._pstr)
{
    cout << "String(const String &)" << endl;
    ++ *(int *)(_pstr - 4);
}

String &String::operator=(const String &rhs)
{
    cout << "String &operator=(const String &)" << endl;
    if(this != &rhs) //自复制
    {
        if(-- *(int *)(_pstr - 4) == 0)//引用计数减到0
        {
            delete [] (_pstr - 4);
            _pstr = nullptr;
        }
        _pstr = rhs._pstr;
        ++ *(int *)(_pstr - 4); 
    }
    return *this;
}

char &String::operator[](size_t idx)
{
    if(idx < size())
    {
        if(getRefCount() > 1)
        {
            -- *(int *)(_pstr - 4);
            char *ptmp = new char[strlen(_pstr) + 5]() + 4;
            strcpy(ptmp,_pstr);
            _pstr = ptmp;
            *(int *)(_pstr - 4) = 1;
        }
        return _pstr[idx];
    }
    else
    {
        static char nullchar = '\0';
        return nullchar;
    }
}

String::~String()
{
    cout << "~String()" << endl;
    if(--*(int *)(_pstr - 4) == 0)
    {
        delete [] (_pstr - 4);
    }
    _pstr = nullptr;
}

const char *String::c_str() const
{
    return _pstr;
}

int String::getRefCount()
{
    return *(int *)(_pstr -4);
}

size_t String::size() const
{
    return strlen(_pstr);
}

ostream &operator<<(ostream &os, const String &rhs)
{
    if(rhs._pstr)
    {
        os << rhs._pstr; //加上解引用符号之后表示的是输出字符数组中第一个字符而不是输出整个字符串
    }
    else
    {
        os << '\0';
    }
    return os;
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

    cout << endl << "对s3[0]执行写操作" << endl;
    s3[0] = 'H';
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

