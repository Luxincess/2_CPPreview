#include <iostream>
using std::endl;
using std::cout;

class Example
{
public:
    Example(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        
    }

    template <class T = int>
    T func()
    {
        return (T)_ix;
    }

private:
    int _ix;
    int _iy;
};


void test()
{
    Example ex(10,20);
    cout << "ex.func() = " << ex.func<int>() << endl;
    cout << "ex.func() = " << ex.func<double>() << endl;
    cout << "ex.func() = " << ex.func() << endl;
}

int main()
{
    test();
    return 0;
}

