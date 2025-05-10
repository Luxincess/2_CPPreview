#include <iostream>
using namespace std;

inline
int add(int x, int y)
{
    return x + y;
}
void test()
{
    int a = 3, b = 4;
    cout << "add(a, b) = " << add(a, b) << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

