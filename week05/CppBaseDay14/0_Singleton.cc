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
        if(_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
private:
    Singleton()
    {
        cout << "Singleton()" << endl;
    }
    ~Singleton()
    {
        cout << "~Singleton()" << endl;
    }
private:
    static Singleton *_pInstance;
};

Singleton *Singleton::_pInstance = nullptr;

void test()
{
    Singleton *ps1 =  Singleton::getInstance();
    Singleton *ps2 = Singleton::getInstance();
    cout << "ps1 = " << ps1 << endl;
    cout << "ps2 = " << ps2 << endl;
    ps1->destroy();
    ps2->destroy();
}

int main()
{
    test();
    return 0;
}

