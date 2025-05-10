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
    pt.~Point();
    pt.print();

    cout << "=========" << endl;
    //匿名对象生命周期只在该行，用完之后马上销毁
    Point().print(); //临时对象，匿名对象。可以通过调用构造函数直接创建对象
    cout << "=========" << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

