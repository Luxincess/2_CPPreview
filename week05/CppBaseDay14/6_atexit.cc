#include <stdlib.h>
#include <iostream>
using namespace std;

void func() //返回值为void,参数列表也为空 atexit(void (*func)(void))
{
    cout << "void func()" << endl;
}

void test()
{
    atexit(func);
    atexit(func);
    atexit(func);
    atexit(func);

}

int main()
{
    cout << "begin main..." << endl;
    test();
    cout << "finish main..." << endl;
    return 0;
}

