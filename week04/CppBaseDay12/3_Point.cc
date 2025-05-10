#include <math.h>
#include <iostream>
using namespace std;

class Point;
class Line
{
public:
    double distance(const Point &lhs, const Point &rhs);
    void setPoint(Point &pt, int ix, int iy);
    int getIZ()
    {
        return _iz;
    }
    void setIZ(int iz)
    {
        _iz = iz;
    }
private:
    int _iz;
};

class Point
{
    friend class Line;
public:
    Point(double ix = 0, double iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(double = 0, double = 0)" << endl;
    }

    void setLine(Line &line, int iz)
    {
        line.setIZ(iz);
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

void Line::setPoint(Point &pt, int ix, int iy)
{
    pt._ix = ix;
    pt._iy = iy;
}
void test()
{
    Line line;
    Point pt1(1,2);
    Point pt2(4,6);
    line.setPoint(pt2, 10, 20);
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

