#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Child; //前向声明
class Parent
{
public:
    Parent()
    {
        cout << "Parent()" << endl;
    }
    ~Parent()
    {
        cout << "~Parent()" << endl;
    }
    weak_ptr<Child> _pChild;
};

class Child
{
public:
    Child()
    {
        cout << "Child()" << endl;
    }
    ~Child()
    {
        cout << "~Child()" << endl;
    }
    shared_ptr<Parent> _wParent; //弱引用的智能指针 不增加引用计数 解决了内存泄漏的问题
};

void test()
{
    shared_ptr<Parent> spParent(new Parent());
    shared_ptr<Child> spChild(new Child());
    cout << "spParent.use_count() = " << spParent.use_count() << endl;
    cout << "spChild.use_count() = " << spChild.use_count() << endl;

    cout << endl;
    //内存泄漏
    spParent->_pChild = spChild;
    spChild->_wParent = spParent;
    cout << "spParent.use_count() = " << spParent.use_count() << endl;
    cout << "spChild.use_count() = " << spChild.use_count() << endl;
}

int main()
{
    test();
    return 0;
}

