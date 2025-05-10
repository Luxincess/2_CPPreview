#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Base
{
public:
    Base(const char *pbase)
    : _pbase(new char[strlen(pbase) + 1]())
    {
        cout << "Base(const char *)" << endl;
        strcpy(_pbase, pbase);
    }

    virtual 
    void print() const
    {
        cout << "Base::_pbase = " << _pbase << endl;
    }

    virtual  //将基类中的析构函数设置为虚函数，那么派生类中的析构函数会自动变为虚函数，认为其是一种重写
    ~Base()
    {
        cout << "~Base()" << endl;
        if(_pbase)
        {
            delete []_pbase;
            _pbase = nullptr;
        }
    }
private:
    char *_pbase;
};

class Derived
: public Base
{
public:
    Derived(const char *pbase, const char *pderived)
    : Base(pbase)
    , _pderived(new char[strlen(pderived) + 1]())
    {
        cout << "Derived(const char *, const char *)" << endl;
        strcpy(_pderived, pderived);
    }

    void print() const override
    {
        cout << "Derived::_pderived = " << _pderived << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
        if(_pderived)
        {
            delete []_pderived;
            _pderived = nullptr;
        }
    }
private:
    char *_pderived;
};

void test()
{
    Base *pbase = new Derived("hello", "world");
    pbase->print();

    delete pbase;
    pbase = nullptr;
}

int main()
{
    test();
    return 0;
}

