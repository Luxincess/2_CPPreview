#include <iostream>
#include <pthread.h>
#include <stdlib.h>
using namespace std;

class Singleton
{
public:
    static Singleton *getInstance()
    {
        pthread_once(&_once, init);
        return _pInstance;
    }

    static void init()
    {
        if(_pInstance == nullptr)
        {
            _pInstance = new Singleton();
            atexit(destroy);
        }
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
    static pthread_once_t _once;
};
//饱汉模式
Singleton *Singleton::_pInstance = nullptr;
//饿汉模式 保证在多线程情况下的代码安全
// Singleton *Singleton::_pInstance = Singleton::getInstance();

pthread_once_t Singleton::_once =   PTHREAD_ONCE_INIT;

void test()
{
    Singleton::getInstance();
}

int main()
{
    test();
    return 0;
}

