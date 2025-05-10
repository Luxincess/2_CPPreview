#include <iostream>
using namespace std;

void test()
{
    const int number = 10;
    //脱去number的常量属性
    int *pInt = const_cast<int *>(&number);
    cout << "number = " << number << endl;
    cout << "*pInt = " << *pInt << endl;

    *pInt = 30;//未定义的行为
    cout << "number = " << number << endl;
    cout << "*pInt = " << *pInt << endl;
    printf("&number = %p\n",&number);
    printf("pInt = %p\n", pInt);

#if 0
    const int *pInt = &number;
    cout << "number = " << number << endl;
    cout << "*pInt = " << *pInt << endl;
    cout << "&number = " << &number << endl;
    cout << "pInt = " << pInt << endl;
    const int value = 20;
    pInt = &value;
    cout << "*pInt = " << *pInt << endl;
#endif
}

void test2()
{
    int number = 20;
    int *pInt = &number;
    *pInt = 30;
    cout << "number = " << number << endl;
    cout << "*pInt = " << *pInt << endl;
    printf("&number = %p\n", &number);
    printf("pInt = %p\n", pInt);
}
int main(int argc, char* argv[])
{
    /* test(); */
    test2();
    return 0;
}

