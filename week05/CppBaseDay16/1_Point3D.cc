#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
    }

    int getY() const
    {
            return _iy;
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
protected:
    int _ix;
private:
    int _iy;
};

class Point3D
: public Point
{
public:
    Point3D(int ix = 0, int iy = 0, int iz = 0)
    : Point(ix, iy)
    , _iz(iz)
    {
        cout << "Point3D(int = 0, int = 0, int = 0)" << endl;
    }

    void print3D()
    {
        cout << "(" << _ix
             << "," << getY()
            << "," << _iz
            << ")" << endl;
    }

    ~Point3D()
    {
        cout << "~Point3D()" << endl;
    }
private:
    int _iz;
};

void test()
{
    cout << "sizeof(Point) = " << sizeof(Point) << endl;
    cout << "szieof(Pointr3D) = " << sizeof(Point3D) << endl;
    Point3D pt3d(1,2,3);
    cout << "pt3d.getY() = " << pt3d.getY() << endl;
    cout << "pt3d = ";
    pt3d.print3D();
}

int main()
{
    test();
    return 0;
}

