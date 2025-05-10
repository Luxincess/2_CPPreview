#include <iostream>
#include <memory>
#include <vector>
using std::endl;
using std::cout;
using std::shared_ptr;
using std::vector;

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

void test()
{
    shared_ptr<Point> sp(new Point(1,2));
    cout << "*sp = ";
    sp->print();
    cout << "sp.get() = " << sp.get() << endl;
    cout << "sp.use_count() = " << sp.use_count() << endl;

    cout << endl;
    shared_ptr<Point> sp2 = sp; //拷贝构造函数
    cout << "*sp = ";
    sp->print();
    cout << "*sp2 = ";
    sp2->print();
    cout << "sp.get() = " << sp.get() << endl;
    cout << "sp2.get() = " << sp2.get() << endl;
    cout << "sp.use_count() = " << sp.use_count() << endl;
    cout << "sp2.use_count() = " << sp2.use_count() << endl;

    cout << endl;
    shared_ptr<Point> sp3(new Point(3,4));
    cout << "*sp3 = ";
    sp3->print();
    cout << "sp3.get() = " << sp3.get() << endl;
    cout << "sp3.use_count() = " << sp3.use_count() << endl;

    cout << endl;
    sp3 = sp;
    cout << "*sp = ";
    sp->print();
    cout << "*sp2 = ";
    sp2->print();
    cout << "*sp3 = ";
    sp3->print();
    cout << "sp.get() = " << sp.get() << endl;
    cout << "sp2.get() = " << sp2.get() << endl;
    cout << "sp3.get() = " << sp3.get() << endl;
    cout << "sp.use_count() = " << sp.use_count() << endl;
    cout << "sp2.use_count() = " << sp2.use_count() << endl;
    cout << "sp3.use_count() = " << sp3.use_count() << endl;

    cout << endl << endl;
    vector<shared_ptr<Point>> vec;
    vec.push_back(sp);
    vec.push_back(sp3);
    vec.push_back(std::move(sp));
    vec.push_back(std::move(sp3));
    vec.push_back(shared_ptr<Point>(new Point(1,9)));
}

int main()
{
    test();
    return 0;
}

