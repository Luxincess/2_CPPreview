#include <sstream>
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::ostream;

class String
{
public:
    String();
    String(const char *pstr);
    String(const String &rhs);
    ~String();
    String &operator=(const String &rhs);
    friend ostream &operator<<(ostream &os, const String &rhs);
private:
    char *_pstr;
};

String::String()
: _pstr(nullptr)
{
    cout << "String()" << endl;
}

String::String(const char *pstr)
: _pstr(new char[strlen(pstr) + 1]())
{
    cout << "String(const char *)" << endl;
    strcpy(_pstr, pstr);
}

String::String(const String &rhs)
: _pstr(new char[strlen(rhs._pstr) + 1]())
{
    cout << "String(const String &)" << endl;
    strcpy(_pstr,rhs._pstr);
}
 
String::~String()
{
    cout << "~String()" << endl;
    if(_pstr)
    {
        delete []_pstr;
        _pstr = nullptr;
    }
}

String &String::operator=(const String &rhs)
{
    cout << "String &operator=(const String &)" << endl;
    if(this != &rhs)
    {
        delete []_pstr;
        _pstr = nullptr;
        _pstr = new char[strlen(rhs._pstr) + 1]();
        strcpy(_pstr, rhs._pstr);
    }
    return *this;
}

ostream &operator<<(ostream &os, const String &rhs)
{
    if(rhs._pstr)
    {
        os << rhs._pstr;
    }
    return os;
}

void test()
{
    String s1;
    cout << s1 << endl;

    String s2("hello");
    cout << s2 << endl;

    String s3 = s2;
    cout << s3 << endl;

    s1 = s3;
    cout << s1 << endl;

}

int main()
{
    test();
    return 0;
}

