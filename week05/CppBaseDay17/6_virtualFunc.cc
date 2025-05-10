#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(long base = 0)
    : _base(base)
    {
        cout << "Base(long = 0)" << endl;
    }

    virtual void print() const
    {
        cout << "Base::_base = " << _base << endl;
    }

    void func1()
    {
        this->print();
    }

    void func2()
    {
        Base::print();
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
    Derived(long base = 0, long derived = 0)
    : Base(base)
    , _derived(derived)
    {
        cout << "Derived(long = 0, long = 0)" << endl;
    }

#if 1
    void print() const
    {
        cout << "Derived::_derived = " << _derived << endl;
    }
#endif

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
private:
    long _derived;
};

void func(Base &ref)
{
    ref.print();
}

void test()
{
    cout << "sizeof(Base) = " << sizeof(Base) << endl;
    cout << "sizeof(Derived) = " << sizeof(Derived) <<endl;
    
    cout << endl;
    Base base(10);
    Derived derived(111,222);

    cout << endl;
    Base *pbase;
    pbase = &base;
    pbase->func1();
    pbase->func2();

    cout << endl;
    pbase = &derived;
    pbase->func1();
    pbase->func2();
}

int main()
{
    test();
    return 0;
}



