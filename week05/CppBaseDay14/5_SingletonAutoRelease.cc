#include <iostream>
using namespace std;

class Singleton
{
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

    class AutoRelease //内部类
    {
    public:
        AutoRelease()
        {
            cout << "AutoRelease()" << endl;
        }
        ~AutoRelease()
        {
            cout << "~AutoRelease()" << endl;
            if(_pInstance)
            {
                delete _pInstance;
                _pInstance = nullptr;
            }
        }
    };
private:
    static Singleton *_pInstance;
    static AutoRelease _ar; //静态数据成员
};

// Singleton *Singleton::_pInstance = nullptr;
Singleton *Singleton::_pInstance = nullptr;
Singleton::AutoRelease Singleton::_ar;


void test()
{
    Singleton::getInstacne();
}

int main()
{
    test();
    return 0;
}

