#include <iostream>
#include <string.h>
#include <ostream>
using std::cout;
using std::endl;
using std::ostream;

class String
{
public:
    String()
    : _pstr(nullptr)
    {
        cout << "String()" << endl;
    }

    String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }

    String(String &rhs) //const左值引用即可以绑定左值也可以绑定右值，但是不能识别左右值
                             //有了移动构造函数之后，就可以将const删掉，这样拷贝构造函数绑左值，移动构造函数绑右值
    : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        cout << "String(const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    String &operator=(const String &rhs)
    {
        cout << "String &operator=(const String &)" << endl;
        if(this != &rhs)
        {
            delete [] _pstr;
            _pstr = nullptr;
            _pstr = new char [strlen(rhs._pstr) + 1]();
            strcpy(_pstr, rhs._pstr);
        }
        return *this;
    }
//移动语义：通过转移资源来避免复制的开销
//移动语义函数会优先于拷贝语义函数执行
    String(String &&rhs)
    : _pstr(rhs._pstr)
    {
        cout << "String(Stirng &&)" << endl;
        rhs._pstr = nullptr;
    }

    String &operator=(String &&rhs)    //移动语义的函数会优先于拷贝语义的函数执行
    {
        cout << "String &operator=(String &&)" << endl;
        if(this != &rhs)
        {
            cout << "000000" << endl;
            delete []_pstr;
            _pstr = nullptr;
            _pstr = rhs._pstr;
            rhs._pstr = nullptr;   //为什么这里要将rhs._pstr置为nullptr,就是因为在析构函数里面需要判断_pstr，
                                   //这里置空就能避免delete掉还不能释放的堆空间
        }
        return *this;
    }

    ~String()
    {
        cout << "~String()" << endl;
        if(_pstr)
        {
            delete [] _pstr;
            _pstr = nullptr;
        }
    }

    friend ostream &operator<<(ostream &os, const String &rhs);
private:
    char *_pstr;
};

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
    cout << s1 << endl;
    cout << endl;
    String s2;
    cout << s2 << endl;
    cout << endl;
    String s3 = s1;
    cout << s3 << endl;
    cout << endl;
    s2 = s3;
    cout << s2 << endl;
}

void test2()
{
    //&String("hello"); error 不能对右值取地址
    String s1 = "hello";
    cout << "s1 = " << s1 << endl;

    cout << endl;
    String s2("hello");
    cout << "s2 = " << s2 << endl;

    cout << endl;
    s2 = String("wangdao"); //移动赋值函数   如果写成 s2 = s1,那么就会调用普通的赋值运算符函数
    cout << "s2 = " << s2 << endl;

    cout << endl;
    String("beijing") = String("beijing");
    cout << endl << "std::move() ===" << endl;

    s2 = std::move(s2);     //左值转化为右值，本身没有什么移动的含义，本质上只是做一个强转static_cast<T &&>(value)
                            //std::move()函数的返回值为一个右值，但是s2本身还是一个左值
    cout << "s2 = " << s2 << endl;
}

int main()
{
    test2();
    return 0;
}

