#include <unistd.h>
#include <iostream>
using namespace std;

void test()
{
    for(size_t idx = 0; idx < 1024; ++idx)
    {
        cout << "a ";
    }
    cout << endl;

    cout << "b" << endl; //刷新并换行
    cout << "hello" << flush; //只刷新，不换行
    cout << "wangdao" << ends; //不刷新不换行
    sleep(3);
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

