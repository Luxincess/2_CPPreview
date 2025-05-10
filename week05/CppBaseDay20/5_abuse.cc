#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using std::enable_shared_from_this;

class Point
: public enable_shared_from_this<Point>
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
    }

    // Point *addPoint(Point *pt)
    shared_ptr<Point> addPoint(Point *pt)
    {
        _ix += pt->_ix;
        _iy += pt->_iy;
        return shared_from_this();
        // return shared_ptr<Point>(this);
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


void test()
{
    shared_ptr<Point> sp(new Point(1,2));
    shared_ptr<Point> sp2(new Point(3,4));
    shared_ptr<Point> sp3(sp->addPoint(sp2.get())); //*实际上sp3和sp托管同一块堆空间，但是引用计数没有增加
    cout << "*sp = " ;
    sp->print();
    cout << "*sp2 = ";
    sp2->print();
    cout << "*sp3 = ";
    sp3->print();
    cout << "sp.get() = " << sp.get() << endl;
    cout << "sp2.get() = " << sp2.get() << endl;
    cout << "sp3.get() = " << sp3.get() << endl;
    cout << "sp.use_count() = " << sp.use_count() << endl;  //*引用计数都为1
    cout << "sp3.use_count() = " << sp3.use_count() << endl;



}



int main()
{
    test();
    return 0;
}

