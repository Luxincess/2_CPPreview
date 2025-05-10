#include <iostream>
using namespace std;

class Point
{
public:
    Point()
    :_ix(0)
    ,_iy(0)
    {
        cout << "Point()" << endl;
    }

    Point(int ix, int iy)
    :_ix(ix)
    ,_iy(iy)
    {
        cout << "Point(ix, iy)" << endl;
    }

    void print()
    {
        cout << "(" << _ix
             << "," << _iy
             << ")" << endl;
    }
private:
    int _ix;
    int _iy;
};

int main(int argc, char* argv[])
{
    Point pt(1,2);
    Point pt2;
    pt.print();
    pt2.print();

    int arr[10];
    printf("%p\n", &arr+1);//0x7ffe5166bff8   对数组取地址，加一个数组所占的字节
    printf("%p\n", arr+1); //0x7ffe5166bfd4   对数组中第一个元素取地址，加一个数组元素所占字节
    printf("%p\n", &arr[0]);//0x7ffe5166bfd0  对数组中第一个元素取地址
    return 0;
}

