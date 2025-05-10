#include "Computer.h"
#include <iostream>
using namespace std;

void test()
{
    Computer com("Thinkpad", 5500);
    cout << "com = ";
    com.print();

    cout << endl;
    Computer com2 = com;
    cout << "com2 = ";
    com2.print();

    cout << endl;
    Computer com3("mac", 20000);
    cout << "com3 = ";
    com3.print();

    cout << endl;
    cout << "com3 = com" << endl;
    com3 = com;
    cout << "com3 = ";
    com3.print();

    cout << endl << "com3 = com3" << endl;
    com3 = com3;//自复制
    cout << "com3 = ";
    com3.print();

}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

