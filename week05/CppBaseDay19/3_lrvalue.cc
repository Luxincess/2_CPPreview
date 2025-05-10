#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void test()
{
    int a = 3;
    int b = 4;
    &a;
    &b;
    //&(a+b);  error 右值
    int *pflag = &a;
    &pflag;
    &*pflag;

    string s1("hello");
    string s2("world");
    &s1;
    &s2;
    //&(s1 + s2); error 右值

    int number = 10;
    int &ref = number;


    int &&rref = 10;
    &rref;

}

int &&func()
{
    return 10;
}

int main()
{
    test();
    //&func(); 右值引用作为函数返回值时是右值
    return 0;
}

