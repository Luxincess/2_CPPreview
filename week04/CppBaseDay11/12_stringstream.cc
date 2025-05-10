#include <sstream>
#include <string>
#include <iostream>
using namespace std;

void test()
{
    int number1 = 10;
    int number2 = 20;
    stringstream ss;
    ss << "number1 = " << number1
       << " ,number2 = " << number2 << endl;
    cout << ss.str();

    string key;
    int value;
    while(ss >> key >> value)
    {
        cout << key << " " << value << endl;
    }
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

