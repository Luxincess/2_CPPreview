#include <iostream>
using namespace std;

class Point
{
public:
    explicit Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
    }

    void print() const
    {
        cout << "(" << _ix
             << "," << _iy
             << ")" << endl;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};

void test()
{
    /* Point pt = 10;//禁止隐式转换 */
    Point pt(10);
    cout << "pt = ";
    pt.print();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

