#include <iostream>
using namespace std;

class Line
{
public:
    Line(int x1, int y1, int x2, int y2)
    : _pt1(x1, y1)
    , _pt2(x2, y2)
    {
        cout << "Line(int, int, int, int)" << endl;
    }

    ~Line()
    {
        cout << "~Line()" << endl;
    }

    void print() const
    {
        cout << "(" << _pt1.getIx() << "," << _pt1.getIy() << ")"
             << "->" << "(" << _pt2.getIx() << "," << _pt2.getIy() << ")"
             << endl; 
    }

// private:
    class Point
    {
    public:
        Point(int ix = 0, int iy = 0)
        : _ix(ix)
        , _iy(iy)
        {
            cout << "Point(int = 0, int = 0)" << endl;            
        }
        ~Point()
        {
            cout << "~Point()" << endl;
        }
        int getIx() const
        {
            return _ix;
        }
        int getIy() const
        {
            return _iy;
        }
    private:
        int _ix;
        int _iy;
    };
private:
    Point _pt1;
    Point _pt2;
};

void test()
{
    //Line::Point pt(1,2); error
    Line line(1,2,3,4);
    line.print();
    // Line::Point pt(1,2); 
}

int main()
{
    test();
    return 0;
}

