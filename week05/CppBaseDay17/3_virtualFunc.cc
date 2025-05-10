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

void func(Base *pbase)
{
    pbase->print();
}

void test()
{
    cout << "sizeof(Base) = " << sizeof(Base) << endl;
    cout << "sizeof(Derived) = " << sizeof(Derived) <<endl;
    cout << endl;
    Base base(10);
    base.print();

    cout << endl;
    Derived derived(111,222);
    derived.print();

    cout << endl;
    func(&base);
    func(&derived);
}

int main()
{
    test();
    return 0;
}



