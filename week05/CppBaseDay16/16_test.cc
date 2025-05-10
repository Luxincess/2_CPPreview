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
    //delete
    Example(const Example &rhs) = delete;
    Example &operator=(const Example &rhs) = delete;
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

