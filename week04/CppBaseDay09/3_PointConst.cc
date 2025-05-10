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
    void print() const
    {
        cout << "(" << this->_ix
             << "," << this->_iy
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
    const Point pt(1,2);
    cout << "pt = ";
    pt.print();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

