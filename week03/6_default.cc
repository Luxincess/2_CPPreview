#include <iostream>
using namespace std;

int add(int x = 0, int y = 10, int z = 2)
{
    return x + y + z;
}

int main(int argc, char* argv[])
{
    int a = 3, b = 4, c = 5;
    cout << "add(a, b, c) = " << add(a, b, c) << endl;
    cout << "add(a, b) = " << add(a, b) << endl;
    cout << "add(a) = " << add(a) << endl;
    cout << "add() = " << add() << endl;
    return 0;
}

