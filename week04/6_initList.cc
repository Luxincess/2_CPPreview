#include <iostream>

using namespace std;

class Example
{
public:
    Example(int value)
    : _iy(value)
    , _ix(_iy)
    {
        cout << "Example(int)" <<endl;
    }

    void print()
    {
        cout << "(" << _ix
             << "," << _iy
             << ")" << endl;
    }
private:
    int _iy;
    int _ix;
};

void test()
{
    Example ex(10);
    ex.print();
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
