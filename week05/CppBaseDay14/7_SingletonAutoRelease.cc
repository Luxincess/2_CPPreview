#include <iostream>
#include <stdlib.h>
using namespace std;

class Singleton
{
public:
    static Singleton *getInstance()
    {
        if(_pInstance == nullptr)
        {
            _pInstance = new Singleton();
            atexit(destroy);                   
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
//饱汉模式
//Singleton *Singleton::_pInstance = nullptr;
//饿汉模式 保证在多线程情况下的代码安全
Singleton *Singleton::_pInstance = Singleton::getInstance();

void test()
{
    Singleton::getInstance();
}

int main()
{
    test();
    return 0;
}

