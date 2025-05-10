#include <iostream>
using namespace std;

class Point
{
public:
    Point(int ix =0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    , _iz(_ix)//_iz与_ix绑定
    {
        cout << "Point(int = 0, int = 0)" << endl;
    }
    void setZ(int iz)
    {
        _iz = iz;//改变_iz,与之绑定的_ix也会改变
    }
    void print()
    {
        cout << "(" << _ix
             << "," << _iy
             << "," << _iz
             << ")" << endl;
    }
    ~Point()
    {
        cout << "~Point()" <<endl;
    }
private:
    int _ix;
    int _iy;
    int &_iz;//实质上是一个指针，指针常量，不能改变指向，能改内容
};
void test()
{
    cout << "sizeof(int) = " << sizeof(int) <<endl;
    cout << "sizeof(Point) = " << sizeof(Point) << endl;

    cout << endl;
    Point pt(1,2);
    cout << "pt = ";
    pt.print();

    cout << endl;
    pt.setZ(100);
    cout << "pt = ";
    pt.print();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

