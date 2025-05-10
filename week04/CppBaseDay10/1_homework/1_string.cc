#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
    String();
    String(const char *pstr);
    String(const String &rhs);
    String &operator=(const String &rhs);
    ~String();
    void print() const;
    const char *c_str();
private:
    char *_pstr;
};

String::String()
: _pstr(nullptr)
{
    cout << "String()" <<endl;
}

String::String(const char *pstr)
: _pstr(new char[strlen(pstr) + 1]())
{
    strcpy(_pstr, pstr);
    cout << "String(cosnt char *)" << endl;
}

String::String(const String &rhs)
: _pstr(new char[strlen(rhs._pstr) + 1]())
{
    cout << "String(const String &)" << endl;
    strcpy(_pstr, rhs._pstr);
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

String::~String()
{
    cout << "~String()" << endl;
    if(_pstr)
    {
        delete []_pstr;
        _pstr = nullptr;
    }
}

void String::print() const
{
    if(_pstr)
    {
        cout << "_pstr = " << _pstr << endl;
    }
}

const char *String::c_str()
{
    return _pstr;
}

void test()
{
    String str1;
    str1.print();
    String str2("hello");
    str2.print();

    cout << endl;
    String str3 = "world";
    str3.print();

    cout << endl;
    String str4 = str3;
    str4.print();

    cout << endl;
    str1 = str2;
    str1.print();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

