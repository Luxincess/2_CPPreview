#include <iostream>
using namespace std;

class Singleton
{
    friend class AutoRelease; //友元类
public:
    static Singleton *getInstacne()
    {
        if(_pInstance == nullptr)
        {
            _pInstance = new Singleton();
        }
        return _pInstance;
    }
    // void destroy(); 通过AutoRelease自动释放
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

class AutoRelease
{
public:
    AutoRelease()
    {
        cout << "AutoRelease()" << endl;
    }
    ~AutoRelease()
    {
        cout << "~AutoRelease()" << endl;
        if(Singleton::_pInstance)
        {
            delete Singleton::_pInstance;
            Singleton::_pInstance = nullptr;
        }
    }
};

void test()
{
    Singleton::getInstacne();
    AutoRelease ar;
}

int main()
{
    test();
    return 0;
}

