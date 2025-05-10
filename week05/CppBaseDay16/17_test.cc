#include <iostream>
using namespace std;

class NonCopyable
{
public:
    NonCopyable()
    {}
    NonCopyable(const NonCopyable &rhs) = delete;
    NonCopyable &operator=(NonCopyable &rhs) = delete;
};

class Example
: NonCopyable
{
public:
    Example()
    {
        cout << "Example()" << endl;
    }
    ~Example()
    {
        cout << "~Example()" << endl;
    }
};

void test()
{
    Example ex1;
    //Example ex2 = ex1; //error
    cout << endl;
    Example ex3;
    //ex3 = ex1; //error
}

int main()
{
    test();
    return 0;
}

