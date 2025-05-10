#include <iostream>
using namespace std;

class Example
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
private:
    Example(const Example &rhs)
    {
        cout << "Example(const Example &)" << endl;
    }
    Example &operator=(const Example &rhs)
    {
        cout << "Example &operator=(const Example &)" << endl;
        return *this;
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

