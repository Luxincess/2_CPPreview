#include <iostream>
#include <vector>
using namespace std;

void test()
{
    vector<int> number;
    cout << "number.size() = " << number.size() << endl;
    cout << "number.capacity() = " << number.capacity() << endl;

    cout << endl;
    number.push_back(1);
    cout << "number.size() = " << number.size() << endl;
    cout << "number.capacity() = " << number.capacity() << endl;

    cout << endl;
    number.push_back(2);
    cout << "number.size() = " << number.size() << endl;
    cout << "number.capacity() = " << number.capacity() << endl;

    cout << endl;
    number.push_back(2);
    cout << "number.size() = " << number.size() << endl;
    cout << "number.capacity() = " << number.capacity() << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

