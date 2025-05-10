#include <iostream>
using namespace std;

class Data
{
public:
    Data(int data = 0)
    : _data(data)
    {
        cout << "Data(int = 0)" << endl;
    }

    int getData() const
    {
        return _data;
    }

    ~Data()
    {
        cout << "~Data()" << endl;
    }
private:
    int _data;
};

class SecondLayer
{
public:
    SecondLayer(Data *pdata)
    : _pdata(pdata)
    {
        cout << "SecondLayer(Data *)" << endl;
    }

    Data *operator->()
    {
        return _pdata;
    }

    Data &operator*()
    {
        return *_pdata;
    }

    ~SecondLayer()
    {
        cout << "~SecondLayer()" << endl;
        if(_pdata)
        {
            delete _pdata;
            _pdata = nullptr;
        }
    }
private:
    Data *_pdata;
};

class ThirdLayer
{
public:
    ThirdLayer(SecondLayer *psl)
    : _psl(psl)
    {
        cout << "ThirdLayer(SecondLayer *)" << endl;
    }

    SecondLayer &operator->()
    {
        return *_psl;
    }

    ~ThirdLayer()
    {
        cout << "~ThirdLayer()" << endl;
        if(_psl)
        {
            delete _psl;
            _psl = nullptr;
        }
    }
private:
    SecondLayer *_psl;
};

void test()
{
    SecondLayer s1(new Data(10));
    cout << "s1->getData() = " << s1->getData() << endl;
    cout << "*(s1).getData() = " << (*s1).getData() << endl;

    ThirdLayer t1(new SecondLayer(new Data(200)));
    cout << "t1.getData() = " << t1->getData() << endl;
}

int main()
{
    test();
    return 0;
}