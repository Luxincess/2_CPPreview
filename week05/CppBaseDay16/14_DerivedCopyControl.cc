#include <string.h>
#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    : _pbase(nullptr)
    {
        cout << "Base()" << endl;
    }

    Base(const char *pbase)
    : _pbase(new char[strlen(pbase) + 1]())
    {
        cout << "Base(const char *)" << endl;
        strcpy(_pbase, pbase);
    }

    Base(const Base &rhs)
    : _pbase(new char[strlen(rhs._pbase) + 1]())
    {
        cout << "Base(const Base &)" << endl;
        strcpy(_pbase, rhs._pbase);
    }
    Base &operator=(const Base &rhs)
    {
        cout << "Base &operator=(const Base &)" << endl;
        if(this != &rhs)
        {
            delete [] _pbase;
            _pbase = nullptr;
            _pbase = new char[strlen(rhs._pbase) + 1]();
            strcpy(_pbase, rhs._pbase);
        }
        return *this;
    }

    ~Base()
    {
        cout << "~Base()" << endl;
        if(_pbase)
        {
            delete _pbase;
            _pbase = nullptr;
        }
    }
    friend ostream &operator<<(ostream &os, const Base &rhs);
private:
    char *_pbase;
};

ostream &operator<<(ostream &os, const Base &rhs)
{
    if(rhs._pbase)
    {
        os << rhs._pbase;
    }
    return os;
}

class Derived
: public Base
{
public:
    Derived(const char *pbase, const char *pderived)
    : Base(pbase)
    , _pderived(new char[strlen(pderived) + 1]())
    {
        cout << "Derived(cosnt char *, const char *)" << endl;    
        strcpy(_pderived, pderived);
    }

    Derived(const Derived &rhs)
    : Base(rhs) //显式调用基类的拷贝构造函数
    , _pderived(new char[strlen(rhs._pderived) + 1]())
    {
        cout << "Derived(const Derived &)" << endl;
        strcpy(_pderived, rhs._pderived);
    }
    Derived(const char *pbase)
    : Base(pbase)
    {
        cout << "Derived(const char *pbase)" << endl;
    }

    Derived &operator=(const Derived &rhs)
    {
        cout << "Derived &opertor=(const Derievd &)" << endl;
        if(this != &rhs)
        {
            //显示调用基类的赋值运算符函数重载
            Base::operator=(rhs);
            delete [] _pderived;
            _pderived = nullptr;
            _pderived = new char [strlen(rhs._pderived) + 1]();
            strcpy(_pderived, rhs._pderived);
        }
        return *this;
    }

    ~Derived()
    {
        cout << "~Derievd()" << endl;
    }
    friend ostream &operator<<(ostream &os, const Derived &rhs);
private:
    char *_pderived;
};

ostream &operator<<(ostream &os, const Derived &rhs)
{
    const Base &ref = rhs;  //向上转型，因为基类里面已经对输出流运算符进行了重载
    if(rhs._pderived)
    {
        os << ref << ", " << rhs._pderived;
    }
    return os;
}

void test()
{
    Derived derived1("hello"," world");
    cout << "derived1 = " << derived1 << endl;
    cout << endl;

    Derived derived2 = derived1;
    cout << "derived1 = " << derived1 << endl;
    cout << "derived2 = " << derived2 << endl;
    
    cout << endl;
    Derived derived3("hubei", "wuhan");
    cout << "derived3 = " << derived3 << endl;

    cout << endl;
    derived3 = derived1;
    cout << "derived1 = " << derived1 << endl;
    cout << "derived3 = " << derived3 << endl;


}

int main()
{
    test();
    return 0;
}

