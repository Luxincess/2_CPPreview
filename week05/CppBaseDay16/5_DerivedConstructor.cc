#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base()
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
};

void test()
{
    Derived derived;
}

int main()
{
    test();
    return 0;
}

