#include "Computer.h"
#include <iostream>

using namespace std;

void test()
{
    Computer com("Thinkpad", 5500);
    com.print();
    com.setBrand("mac");
    com.setPrice(8800);
    com.print();
    Computer *pc = new Computer("xiaomi",6000);
    delete pc;
    pc =nullptr;
}
int main(int argc, char *argv[])
{
    cout << "...start main..." << endl;
    test();
    cout << "...finish test..." << endl;
    return 0;
}
