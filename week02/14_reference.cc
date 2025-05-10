#include <iostream>
using namespace std;

void test()
{
    /* const int num = 20; */
    /* num = 30; */
    int number = 10;
    int &ref = number;//引用是变量的别名
    cout << "number = " << number << endl;
    cout << "ref = " << ref << endl;
    /* cout << "&number = " << &number << endl; */
    /* cout << "&ref    = " << &ref << endl; */
    printf("&number = %p\n", &number);//%p表示打印地址
    printf("&ref = %p\n", &ref);
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

