#include <iostream>
#include <limits>
#include <string>
using namespace std;

void printStreamStatus()
{
    cout << "cin.badbit = " << cin.bad() << endl;
    cout << "cin.failbit = " << cin.fail() << endl;
    cout << "cin.eofbit = " << cin.eof() << endl;
    cout << "cin.goodbit = " << cin.good() << endl;
}

void test()
{
    int number = 0;
    printStreamStatus();
    cin >> number;
    printStreamStatus();

    cout << "number = " << number << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//清空缓冲区
    printStreamStatus();

    string s1;
    cin >> s1;
    cout << "s1 = " << s1 << endl;
}

void test2()
{
    int number = 0;
    while(cin >> number, !cin.eof())//ctrl + d结束
    {
        if(cin.bad())
        {
            cout << "stream is bad" << endl;
            return;
        }
        else if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "pls input int data" << endl;
        }
        else
        {
            cout << "number = " << number << endl;
        }
    }
}

int main(int argc, char* argv[])
{
    test2();
    return 0;
}

