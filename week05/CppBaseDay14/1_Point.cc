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
    ~Point()
    {
        cout << "~Point()" << endl;
    }
    friend ostream &operator<<(ostream &os,const Point &rhs);
private:
    int _ix;
    int _iy;
};

ostream &operator<<(ostream &os, const Point &rhs)
{
    os << "(" << rhs._ix << "," << rhs._iy << ")";
    return os;
}

void test()
{
    Point pt(3,5);
    cout << "pt = " << pt << endl;
}

int main()
{
    test();
    return 0;
}


