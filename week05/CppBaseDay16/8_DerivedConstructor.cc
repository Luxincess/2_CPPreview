#include <iostream>
using std::cout;
using std::endl;

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }
    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

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
    Derived(long derived)
    : Base(derived)
    , _derived(derived)
    {
        cout << "Derived(long)" << endl;
    }
    Derived(long base, long derived)
    : _tst()
    , Base(base)
    , _derived(derived)
    {
        cout << "Derived(long, long)" << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }

private:
    long _derived;
    Test _tst;
};

void test()
{
    Derived derived(1,2);
}

int main()
{
    test();
    return 0;
}

