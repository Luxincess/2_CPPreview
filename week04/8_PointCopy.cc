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

    Point(Point const &rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy)
    {
        cout << "Point(Point const &)" << endl;
    }
    void print()
    {
        cout << "(" << this->_ix
             << "," << this->_iy
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

void func(Point pt)
{
    cout << "pt = ";
    pt.print();
}

Point func2()
{
    Point pt3(4,5);
    cout << "pt3 = ";
    pt3.print();
    return pt3;
}
void test()
{
    Point pt(1,2);
    pt.print();
    Point pt2 = pt;
    pt2.print();
    func(pt2);

    Point pt4 = func2();
    cout << "pt4 = ";
    pt4.print();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

