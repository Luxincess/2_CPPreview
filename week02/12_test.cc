#include <iostream>
using namespace std;

int *func()
{
    int number = 10;
    int *p = &number;
    return p;
}

int func2()
{
    return 10;
}

int func3()
{
    return 20;
}

int func4(int x, int y)
{
    return x+y;
}

int (*pFunc)();//函数指针

void test()
{
    pFunc = &func2;
    pFunc = &func3;
    /* pFunc = &func4; */

    int arr[10];
    int ary[30];
    int (*parr)[10];
    parr = &arr;
    /* parr = &ary; */
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

