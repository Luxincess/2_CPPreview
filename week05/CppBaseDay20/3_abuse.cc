#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
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
private:
    int _ix;
    int _iy;
};

void test0()
{
    int *pInt = new int(10);
    unique_ptr<int> up(pInt);
    //unique_ptr<int> up2(pInt); //double free
}
void test()
{
    Point *pt = new Point(1,2);
    unique_ptr<Point> up(pt);
    //unique_ptr<Point> up2(pt); //使用不同的智能指针托管了同一块堆空间
}

void test2()
{
    unique_ptr<Point> up(new Point(3,4));
    cout << "up = ";
    up->print();

    cout << endl;
    unique_ptr<Point> up2(new Point(3,4));
    cout << "up2 = ";
    up2->print();

    // cout << endl;
    // //up.reset(up2.get());
    // cout << "up = ";
    // up->print();
    // cout << "up2 = ";
    // up2->print();
}

int main()
{
    //test0();
    //test();
    test2();
    return 0;
}

