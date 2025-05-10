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


void test()
{
    Point *pt = new Point(1,2);
    shared_ptr<Point> sp(pt);
    shared_ptr<Point> sp2 = sp;
    cout << "sp.use_count() = " << sp.use_count() << endl;
    cout << "sp2.use_count() = " << sp2.use_count() << endl;
}

void test2()
{
    shared_ptr<Point> sp(new Point(1,2));
    cout << "sp = ";
    sp->print();
    cout << "sp.use_count() = " << sp.use_count() << endl;

    cout << endl;
    shared_ptr<Point> sp2(new Point(3,4));
    cout << "sp2 = ";
    sp2->print();
    cout << "sp2.use_count() = " << sp2.use_count() << endl;

    cout << endl;
    //* 需要注意reset的用法：
    //* 如果调用reset()没有提供新的对象，智能指针会释放当前管理的对象，但不会指向任何新对象
    //* 如果调用reset()时提供了新的对象，shared_ptr会开始管理这个新对象，并增加新对象的引用计数
    //* 但是如果新对象已经被其他的shared_ptr管理，引用计数不会增加，因为reset()不会创建新的shared_ptr实例，而是直接接管现有的对象
    //sp.reset(sp2.get());  //! 所以这里就会出现有两个shared_ptr指向同一块堆空间，但是引用计数只为1，然后就会double free
    // cout << "sp = ";
    // sp->print();
    // cout << "sp.use_count() = " << sp.use_count() << endl;
    // cout << "sp2 = ";
    // sp2->print();
    // cout << "sp2.use_count() = " << sp2.use_count() << endl;

}

int main()
{
    //test0();
    // test();
    test2();
    return 0;
}

