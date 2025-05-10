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
};

class Derived
: public Base
{
public:
    Derived(long derived)
    : Base()
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

