#include <math.h>
#include <iostream>
using namespace std;

class Point
{
    friend double distance(const Point &lhs, const Point &rhs);
public:
    Point(double ix = 0, double iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(double = 0, double = 0)" << endl;
    }

    void print() const
    {
        cout << "(" << _ix
             << "," << _iy
             << ")"; 
    }
    ~Point()
    {
        cout << "~Point()" << endl;
    }

private:
    double _ix;
    double _iy;
};

double distance(const Point &lhs, const Point &rhs)
{
    return hypot(lhs._ix - rhs._ix, lhs._iy - rhs._iy);
}
void test()
{
    Point pt1(1,2);
    Point pt2(4,6);
    pt1.print();
    cout << "----->";
    pt2.print();
    cout << "之间的距离 " << distance(pt1,pt2) << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

