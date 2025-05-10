#include <iostream>
using namespace std;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
    }

    Point(const Point &rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy)
    {
        cout << "Point(cosnt Point &)" << endl;
    }

    Point &operator=(Point const &rhs)
    {
        cout << "Point &operator=(Point const &)" << endl;
        _ix = rhs._ix;
        _iy = rhs._iy;
        return *this;
    }

    void print()
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
    Point pt(1,2);
    pt.print();

    Point pt2 = pt;
    pt2.print();

    Point pt3(4,5);
    pt3.print();

    pt2 = pt3;
    pt2.print();

    pt = pt2 = pt3;
    pt.print();
    pt2.print();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

