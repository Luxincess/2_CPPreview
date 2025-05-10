#include "stringOperator.h"

void test()
{
    String s1;
    cout << "s1 = " << s1 << endl;

    cout << endl << endl;
    String s2 = "hello";
    cout << "s2 = " << s2 << endl;

    cout << endl << endl;
    s2 = "world";
    cout << "s2 = " << s2 << endl;

    cout << endl << endl;
    s2 = s2;
    cout << "s2 = " << s2 << endl;

    cout << endl << endl;
    String s3 = "wuhan";
    s3 += "welcome to string world";
    cout << "s3 = " << s3 << endl;
}

int main()
{
    test();
    return 0;
}
