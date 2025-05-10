#include <iostream>
#include <string>
using namespace std;

void test()
{   //短字符串优化 字符串长度小于16字节，位于栈上；字符串长度大于等于16字节，位于堆上 ubuntu2204使用的就是短字符串优化
    int *pInt = new int(10);
    printf("pInt = %p\n", pInt);  //堆空间
    printf("&pInt = %p\n", &pInt); //栈空间
    string s1("hello");
    string s2("helloworldwuhan");
    string s3("welcometowuhanwangdao");
    printf("&s1 = %p\n", s1.c_str()); //栈
    printf("&s2 = %p\n",s2.c_str());  //栈
    printf("&s3 = %p\n", s3.c_str());  //堆

    delete pInt;
    pInt = nullptr;
}

int main()
{
    test();
    return 0;
}

