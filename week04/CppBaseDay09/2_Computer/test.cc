#include "Computer.h"
#include <iostream>
using namespace std;

void test()
{
    /* cout << "sizeof(Computer) = " << sizeof(Computer) << endl; */
    Computer::printTotalPrice();
    Computer com("Thinkpad", 5500);
    Computer::printTotalPrice();
    com.printTotalPrice();

    cout << endl;
    Computer com2("mac", 20000);
    com.printTotalPrice();
    com2.printTotalPrice();
    Computer::printTotalPrice();

    cout << endl;
    com.print();//非const对象默认调用非const版本的成员函数
    cout << endl;
    com2.print();

    const Computer com3("hp",6000);
    com3.print();//const对象默认调用const版本的成员函数，并且不能调用非const版本的成员函数
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

