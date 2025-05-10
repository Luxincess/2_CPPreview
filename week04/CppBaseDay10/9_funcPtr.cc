#include <iostream>
using namespace std;

int func1(int x, int y)
{
    cout << "int func1(int, int)" << endl;
    return x + y;
}

int func2(int a, int b)
{
    cout << "int func2(int, int)" << endl;
    return a * b;
}

void test()
{
    int (*pf)(int, int);
    pf = &func1;
    cout << "pf(100, 200) = " << pf(100, 200) << endl;
    cout << endl;
    pf = func2;
    cout << "pf(10, 50) = " << pf(10, 50) << endl;
}

void func4(int (*pt)(int, int))
{
    cout << "func4 = " << pt(2000, 8000) << endl;
}

int main(int argc, char* argv[])
{
    /* test(); */
    func4(&func1);
    return 0;
}

