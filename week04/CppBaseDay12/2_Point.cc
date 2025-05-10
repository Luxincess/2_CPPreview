#include <math.h>
#include <iostream>
using namespace std;

class Point;
class Line
{
public:
    double distance(const Point &lhs, const Point &rhs);
    double distance(const Point &rhs);
};

class Point
{
    friend double Line::distance(const Point &lhs, const Point &rhs);
    friend double Line::distance(const Point &rhs);
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

double Line::distance(const Point &lhs, const Point &rhs)
{
    return hypot(lhs._ix - rhs._ix, lhs._iy - rhs._iy);
}

double Line::distance(const Point &rhs)
{
    return hypot(rhs._ix, rhs._iy);
}
void test()
{
    Line line;
    Point pt1(1,2);
    Point pt2(4,6);
    pt1.print();
    cout << "----->";
    pt2.print();
    cout << "之间的距离 " << line.distance(pt1,pt2) << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

