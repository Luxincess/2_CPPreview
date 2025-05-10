#include <iostream>
using namespace std;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
    }
#if 1
    operator int()
    {
        cout << "operator int()" << endl;
        return _ix + _iy;
    }
    ~Point()
    {
        cout << "~Point()" << endl;
    }
#endif
private:
    int _ix;
    int _iy;
};

void test()
{
    Point pt(3,5);
    cout << "pt = " << pt << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

