#include "stringOperator.h"

String::String()
: _pstr(new char[1]())
{
    cout << "String()" << endl;
}

String::String(const String &rhs)
: _pstr(new char[strlen(rhs._pstr) + 1]())
{
    cout << "String(const Stirng &)" <<endl;
    strcpy(_pstr, rhs._pstr);
}

String::String(const char *pstr)
: _pstr(new char[strlen(pstr) + 1]())
{
    cout << "String(const char *)" << endl;
    strcpy(_pstr, pstr);
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
    if(_pstr != rhs._pstr)
    {
        delete []_pstr;
        _pstr = nullptr;
        _pstr = new char[strlen(rhs._pstr) + 1]();
        strcpy(_pstr, rhs._pstr);
    }
    return *this;
}

String &String::operator=(const char *pstr)
{
    cout << "String &operator=(const char *)" << endl;
    String tmp(pstr);
    *this = tmp;
    return *this;
}

String &String::operator+=(const String &rhs)
{
    cout << "String &operator+=(const String &)" << endl;
    String tmp = *this; //临时对象
    delete []_pstr;
    _pstr = nullptr;
    _pstr = new char[strlen(tmp._pstr) + strlen(rhs._pstr) + 1]();
    strcpy(_pstr, tmp._pstr);
    strcat(_pstr, rhs._pstr);
    return *this;
}

String &String::operator+=(const char *pstr)
{
    cout << "String &operator+=(const char *)" << endl;
    String tmp(pstr); //临时对象
    *this += tmp; //调用上面的operator+=重载
    return *this;
}

char &String::operator[](size_t index)
{
    cout << "char &operator[](size_t)" << endl;
    if(index < size())
    {
        return _pstr[index];
    }
    else
    {
        static char nullchar = '\0';
        return nullchar;
    }
}

const char &String::operator[](size_t index) const
{
    cout << "const char &operator[](size_t) const" << endl; 
    if(index < size())
    {
        return _pstr[index];
    }
    else
    {
        static char nullchar = '\0';
        return nullchar;
    }
}

size_t String::size() const
{
    return strlen(_pstr);
}

const char* String::c_str() const
{
    return _pstr;
}

bool operator==(const String &lhs, const String &rhs)
{
    cout << "bool operator==(const String &, const String &)" << endl;
    // if(lhs._pstr == rhs._pstr)
        // return true;
    // else
    //     return false;
    return !strcmp(lhs._pstr, rhs._pstr);
}

bool operator!=(const String &lhs, const String &rhs)
{
    cout << "bool operator!=(const String &, const String &)" << endl;
    // if(lhs._pstr != rhs._pstr)
    //     return true;
    // else
    //     return false;
    return strcmp(lhs._pstr, rhs._pstr);
}

bool operator<(const String &lhs, const String &rhs)
{
    cout << "bool operator<(const String &lhs, const String &rhs)" << endl;
    return strcmp(lhs._pstr, rhs._pstr) < 0;
}

bool operator>(const String &lhs, const String &rhs)
{
    cout << "bool operator>(const String &lhs, const String &rhs)" << endl;
    return strcmp(lhs._pstr, rhs._pstr) > 0;
}

bool operator<=(const String &lhs, const String &rhs)
{
    cout << "bool operator<=(const String &lhs, const String &rhs)" << endl;
    return strcmp(lhs._pstr, rhs._pstr) <= 0;
}

bool operator>=(const String &lhs, const String &rhs)
{
    cout << "bool operator>=(const String &lhs, const String &rhs)" << endl;
    return strcmp(lhs._pstr, rhs._pstr) >= 0;
}

ostream &operator<<(ostream &os, const String &s)
{
    //cout << "ostream &operator<<(ostream &, const String &)" << endl;
    if(s._pstr)
    {
        os << s._pstr;
    }
    return os;
}

istream &operator>>(istream &is, String &s)
{
    //cout << "istream &operator>>(istream &, String &)" << endl;
    //可能s里面有字符串，需要先回收
    if(s._pstr)
    {
        delete []s._pstr;
        s._pstr = nullptr;
    }
    vector<char> buffer; //缓冲区，用来存储输入流进来的字符
    char ch;
    while(ch = is.get(), ch != '\n')
    {
        buffer.push_back(ch);
    }
    s._pstr = new char[buffer.size() + 1]();
    strncpy(s._pstr, &buffer[0], buffer.size());
    return is;
}

String operator+(const String &lhs, const String &rhs)
{
    cout << "String operator+(const String &, const String &)" << endl;
    String tmp(lhs);
    tmp += rhs;
    return tmp;
}

String operator+(const String &lhs, const char *pstr)
{
    cout << "String operator+(const String &, const char *)" << endl;
    String tmp(lhs);
    tmp += pstr;
    return tmp;
}

String operator+(const char *pstr, const String &rhs)
{
    cout << "String operator+(const char *, const String &)" << endl;
    String tmp(pstr);
    tmp += rhs;
    return tmp;
}