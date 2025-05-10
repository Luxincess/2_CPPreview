#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

void test()
{
    char str1[] = "hello";
    char str2[] = {'w', 'o', 'r', 'l', 'd', '\0'};

    cout << "strlen(str1) = " << strlen(str1) << endl;
    cout << "strlen(str2) = " << strlen(str2) << endl;
    cout << "sizeof(str1) = " << sizeof(str1) << endl;
    cout << "sizeof(str2) = " << sizeof(str2) << endl;

    char* pstr = "hello,world";
    char* pstr1 = "ustc";
    int a = 10;
    int* pInt = &a;
    cout << "strlen(pstr) = " << strlen(pstr) << endl;
    cout << "sizeof(pstr) = " << sizeof(pstr) << endl;
    cout << "sizeof(pstr1) = " << sizeof(pstr1) << endl;
    cout << "pstr = " << pstr << endl;
    cout << "&pstr = " << &pstr << endl;
    printf("pstr = %p\n", pstr);
    printf("pstr = %s\n", pstr);
    /* printf("pInt = %p\n", pInt); */
    /* printf("pInt = %d\n", pInt); */
    /* printf("*pInt = %d\n", *pInt); */
    /* cout << "pInt = " << pInt << endl; */
    cout << "*pstr = " << *pstr << endl;
    cout << "sizeof(*pstr) = " << sizeof(*pstr) << endl;

    cout << endl;
    size_t len = sizeof(str1) + sizeof(str2);
    char* ptmp = new char[len]();
    strcpy(ptmp,str1);
    strcat(ptmp,str2);
    cout << "ptmp = " << ptmp << endl;

    delete [] ptmp;
    ptmp = nullptr;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

