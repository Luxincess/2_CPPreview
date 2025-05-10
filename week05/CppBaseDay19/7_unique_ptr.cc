#include <iostream>
#include <memory>
#include <vector>
using std::endl;
using std::cout;
using std::unique_ptr;
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
    unique_ptr<Point> up(new Point(1,2));  //智能指针托管，防止内存泄漏，自动回收堆空间
    cout << "*up = ";
    up->print();
    cout << "up.get() = " << up.get() << endl;

    cout << endl;
    //unique_ptr<Point> up2 = up; unique_ptr中的拷贝构造函数被删除了
    cout << endl;
    unique_ptr<Point> up3(new Point(3,4));
    cout << endl;
    //up3 = up; 赋值运算符函数也被删除了
    vector<unique_ptr<Point>> vec;
    //vec.push_back(up); //使用了被删除的拷贝构造函数？
    //为什么这里vector使用了delete的拷贝构造函数？
    //因为vector是一个值语义的容器，他存储的是元素的副本，而不是指针或者引用，当使用push_back向vector中插入一个对象时，他会创建
    //一个副本存储到内部的动态数组中，因此会调用拷贝构造函数来完成这个操作
    vec.push_back(std::move(up)); //作为容器元素时，可以传右值  将左值转换成右值，然后使用移动构造函数
    vec.push_back(std::move(up3));
    vec.push_back(unique_ptr<Point>(new Point(1,9)));
}

int main()
{
    test();
    return 0;
}

