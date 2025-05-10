#include <iostream>
using namespace std;

int func1(int x)
{
    cout << "int func1(int)" << endl;
    return x;
}
int func2(int y)
{
    cout << "int func2(int)" << endl;
    return 2 * y;
}

void test()
{
    int (*pf)(int);
    pf = &func1;
    cout << "pf(100) = " << pf(100) << endl;
    pf = func2;
    cout << "pf(100) = " << pf(100) << endl;
}

void func4(int (*pt)(int))
{
    cout << "func4 = " << pt(2000) << endl;
}
int main(int argc, char* argv[])
{
    /* test(); */
    func4(&func1);
    return 0;
}

