#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class RAII //使用栈对象的生命周期管理资源，当栈对象达到生命周期时，会自动执行析构函数，自动回收堆空间
{
public:
    RAII(T *pdata) //在构造函数里初始化资源
    : _pdata(pdata)
    {
        cout << "RAII(T *)" << endl;
    }

    ~RAII() //在析构函数中释放资源
    {
        cout << "~RAII()" << endl;
        if(_pdata){
            delete _pdata;
            _pdata = nullptr;
        }
    }

    //提供若干访问资源的方法
    T *operator->()
    {
        return _pdata;
    }

    T &operator*()
    {
        return *_pdata;
    }

    T *get() const 
    {
        return _pdata;
    }

    void reset(T *pdata)
    {
        if(_pdata)
        {
            delete _pdata;
            _pdata = nullptr;
        }
        _pdata = pdata;
    }

    RAII(const RAII &rhs) = delete;
    RAII &operator=(const RAII &rhs) = delete;

private:
    T *_pdata;
};

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
    RAII<Point> pt(new Point(1,2));
    pt->print();
    (*pt).print();

    cout << endl << "===执行reset===" << endl;
    pt.reset(new Point(4,5));
    pt->print();
}

int main()
{
    test();
    return 0;
}

