#include <iostream>
using namespace std;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int iy = 0)" << endl;
    }
    void print()
    {
        cout << "(" << this->_ix
             << "," << this->_iy
             << ")";
    }
    ~Point()
    {
        cout << "~Point()" <<endl;
    }
private:
    int _ix;
    int _iy;
};

class Line
{
public:
    Line(int x1, int y1, int x2, int y2)
    : _pt1(x1,y1)
    , _pt2(x2,y2)
    {
        cout << "Line(int, int, int, int)" << endl;
    }
    void print()
    {
        _pt1.print();
        cout << "=======>";
        _pt2.print();
        cout << endl;
    }
    ~Line()
    {
        cout << "~Line()" <<endl;
    }
private:
    Point _pt1;
    Point _pt2;
};
void test()
{
    Line line(1,2,3,4);
    line.print();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

