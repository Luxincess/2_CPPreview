#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void test()
{
    string s1 = "hello";
    string s2(s1);
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    //深拷贝
    printf("&s1 = %p\n", s1.c_str());
    printf("&s2 = %p\n", s2.c_str()); 

    cout << endl;
    string s3 = "world";
    cout << "s3 = " << s3 << endl;
    printf("&s3 = %p\n", s3.c_str());

    cout << endl;
    s3 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("&s1 = %p\n", s1.c_str());
    printf("&s2 = %p\n", s2.c_str());
    printf("&s3 = %p\n", s3.c_str());    

    cout << endl << "对s3[0]执行写操作" << endl;
    s3[0] = 'H';
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("&s1 = %p\n", s1.c_str());
    printf("&s2 = %p\n", s2.c_str());
    printf("&s3 = %p\n", s3.c_str());    

    cout << "sizeof(s1) = " << sizeof(s1) << endl;

    const char *pstr = "hello";
    cout << "sizeof(pstr) = " << sizeof(pstr) << endl;

}

int main()
{
    test();
    return 0;
}

