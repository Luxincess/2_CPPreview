#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    : _base(0)
    {
        cout << "Base()" << endl;
    }

    Base(long base)
    : _base(base)
    {
        cout << "Base(long)" << endl;
    }

    void show() const
    {
        cout << "Base::_base = " << _base << endl;
    }

    ~Base()
    {
        cout << "~Base()" << endl;
    }
private:
    long _base;
};

class Derived
: public Base
{
public:
    Derived()
    : Base(0)
    , _derived(0)
    {
        cout << "Derived()" << endl;
    }

    Derived(long base, long derived)
    : Base(base)
    , _derived(derived)
    {
        cout << "Derived(long, long)" << endl;
    }

    void print() const
    {
        show();
        cout << "Derived::_derived() = " << _derived << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }

private:
    long _derived;
};

void test()
{
    Base base(100);
    base.show();
    cout << endl;
    Derived derived(111,222);
    derived.print();
    cout << "从派生类对象向基类对象进行转换" << endl;
    base = derived;
    base.show();
    cout << endl;
    Base &ref = derived;
    ref.show();
    cout << endl;
    Base *pbase = &derived;
    pbase->show();
}

void test2()
{
    Base base(22);
    base.show();
    cout << endl;
    Derived derived(1000,2000);
    derived.print();
    cout << endl << "从基类对象向派生类对象进行转换" << endl;
    //derived = base; error
    cout << endl;
    //Derived &ref = base; error
    cout << endl;
    //Derived *pderived = &base; error
    
    //强制类型转换
    Derived *pderived2 = static_cast<Derived *>(&base); //不安全的

    Base *pbase = &derived;
    Derived *pderived3 = static_cast<Derived *>(pbase); //安全的
}

int main()
{
    test2();
    return 0;
}

