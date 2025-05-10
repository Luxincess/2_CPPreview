#include <iostream>
using std::cout;
using std::endl;

template <class T>
class Test
{
public:
    //* 14_virtualTest.cc:10:5: error: templates may not be ‘virtual’
   //*10 |     virtual K add(K x, K y)
   //*|     ^~~~~~~
    template <class K>
    virtual K add(K x, K y) //成员函数模板不能为虚函数
    {
        return x + y;
    }
private:
    T _ix;
};

void test()
{
}

int main()
{
    test();
    return 0;
}

