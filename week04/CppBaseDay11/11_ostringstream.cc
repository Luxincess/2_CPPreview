#include <sstream>
#include <string>
#include <iostream>
using namespace std;

string intToString(int value)
{
    ostringstream oss;
    oss << value;
    return oss.str();
}

void test()
{
    int number = 10;
    string tmp = intToString(number);
    cout << "tmp = " << tmp << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

