#include <string.h>
#include <iostream>
using namespace std;

void test()
{
    const char* pstr = "hello,world";
    cout << "pstr = " << pstr << endl;
    cout << "strlen(pstr) = " << strlen(pstr) << endl;
    /* pstr[0] = 'H'; */
    pstr = "wuhan";
    cout << "pstr = " << pstr << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

