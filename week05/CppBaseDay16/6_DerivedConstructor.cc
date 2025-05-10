#include <iostream>
using std::cout;
using std::endl;

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
private:
    long _derived;
};

void test()
{
    Derived derived(10);
}

int main()
{
    test();
    return 0;
}

