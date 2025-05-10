#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton *getInstance()
    {
        if(_pInstance == nullptr)
        {
            _pInstance = new Singleton();
        }
        return _pInstance;
    }

    static void destroy()
    {
        cout << "destroy()" << endl;
        if(_pInstance != nullptr)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
private:
    Singleton()
    {
        cout << "Singleton()" <<endl;
    }
    ~Singleton()
    {
        cout << "~Singleton()" <<endl;
    }
    static Singleton *_pInstance;
};

Singleton *Singleton::_pInstance = nullptr;//静态数据成员在类外进行初始化

void test()
{
    Singleton *p1 = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    p1->destroy();
    p2->destroy();
    Singleton::destroy();
    Singleton::destroy();
}
int main(int argc, char* argv[])
{
    test();
    return 0;
}

