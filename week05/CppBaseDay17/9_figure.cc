#include <iostream>
#include <math.h>
using std::cout;
using std::endl;

class Figure //抽象类，作为接口
{
public:
    virtual void display() const = 0;  //图形种类
    virtual void area() const = 0;     //求面积
};

class Rectangle
: public Figure
{
public:
    Rectangle(double length, double width)
    : _length(length)
    , _width(width)
    {
        cout << "Rectangle(double, double)" << endl;
    }
    void display() const override
    {
        cout << "Rectangle" << endl;
    }

    void area() const override
    {
        cout << "area = " << _length * _width << endl;
    }

    ~Rectangle()
    {
        cout << "~Rectangle()" << endl;
    }
private:
    double _length;
    double _width;
};

class Circle
: public Figure
{
public:
    Circle(double radius)
    : _radius(radius)
    {
        cout << "Circle(double)" << endl;
    }

    void display() const override
    {
        cout << "Circle" << endl;
    }

    void area() const override
    {
        cout << "area = " << 3.14 * _radius * _radius << endl;
    }

    ~Circle()
    {
        cout << "~CIrcle()" << endl;
    }
private:
    double _radius;
};

class Triangle
: public Figure
{
public:
    Triangle(double a, double b, double c)
    : _a(a)
    , _b(b)
    , _c(c)
    {
        cout << "Triangle(double, double, double)" << endl;
    }

    void display() const override
    {
        cout << "Triangle" << endl;
    }

    void area() const override
    {
        double tmp = (_a + _b + _c)/2;
        cout << "area = " << sqrt(tmp * (tmp-_a) *(tmp-_b) * (tmp-_c)) << endl;
    }

    ~Triangle()
    {
        cout << "~Triangle()" << endl;
    }
private:
    double _a;
    double _b;
    double _c;
};

void func(const Figure &fig)
{
    fig.display();
    fig.area();
}

void test()
{
    Rectangle rec(10,20);
    Circle cir(10);
    Triangle tri(3,4,5);

    func(rec);
    func(cir);
    func(tri);
}

int main()
{
    test();
    return 0;
}

