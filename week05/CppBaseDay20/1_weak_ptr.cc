#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;



void test()
{
    weak_ptr<int> wp;
    //块作用域
    {
        shared_ptr<int> sp(new int(10));
        wp = sp;
        cout << "*sp = " << *sp << endl;
        cout << "sp.use_count() = " << sp.use_count() << endl;
        cout << "wp.use_count() = " << wp.use_count() << endl;

        cout << endl;
        shared_ptr<int> sp2 = wp.lock();
        if(sp2)
        {
            cout << "提升成功，wp托管的资源还在" << endl;
            cout << "*sp2 = " << *sp2 << endl;
            cout << "sp.use_count() = " << sp.use_count() << endl;
            cout << "sp2.use_count() = " << sp2.use_count() << endl;
            cout << "wp.use_count() = " << wp.use_count() << endl;
        }
        else
        {
            cout << "提升失败" << endl;
        }

        bool flag = wp.expired();
        if(flag)
        {
            cout << "托管的空间已经不在了" << endl;
        }
        else
        {
            cout << "托管的空间还在" << endl;
        }
    }

    cout << endl;
    shared_ptr<int> sp2 = wp.lock();
    cout << "wp.use_count() = " << wp.use_count() << endl;
    if(sp2)
    {
        cout << "提升成功，wp托管的资源还在" << endl;
        cout << "*sp2 = " << *sp2 << endl;
    }
    else
    {
        cout << "提升失败" << endl;
    }

    bool flag = wp.expired();
    if(flag)
    {
        cout << "托管的空间不在了" << endl;
    }
    else
    {
        cout << "托管的空间还在" << endl;
    }
}

int main()
{
    test();
    return 0;
}

