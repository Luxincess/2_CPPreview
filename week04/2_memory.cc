#include <string.h>
#include <iostream>
using namespace std;

int a = 0;
char *p1;

int main(int argc, char* argv[])
{
    int b;
    char s[] = "123456";
    char *p2;
    const char *p3 = "123456";
    static int c = 0;
    p1 = new char[10];
    p2 = new char[5];
    strcpy(p1, "123456");

    cout << "打印变量的地址" << endl;
    printf("&b = %p\n", &b);
    printf("&a = %p\n", &a);
    printf("&p1 = %p\n", &p1);
    printf("p1 = %p\n", p1);
    printf("&p2 = %p\n", &p2);
    printf("p2 = %p\n", p2);

    cout << "打印变量的值" << endl;
    cout << a << endl;
    cout << b << endl;

    delete p1;
    p1 = nullptr;
    delete p2;
    p2 = nullptr;
    return 0;
}

