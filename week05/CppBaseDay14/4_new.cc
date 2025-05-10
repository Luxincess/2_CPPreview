#include <iostream>
using namespace std;

void test()
{
    int *pInt = new int(10);
    delete pInt;
    pInt = nullptr;
}

int main()
{
    test();
    return 0;
}

