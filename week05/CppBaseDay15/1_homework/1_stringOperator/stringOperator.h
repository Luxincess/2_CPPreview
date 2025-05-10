#ifndef __STRINGOPERATOR_H__
#define __STRINGOPERATOR_H__

#include <iostream>
#include <string.h>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

class String 
{
public:
    String();
    String(const char *pstr);
    String(const String &rhs);
    ~String();
    String &operator=(const String &rhs);
    String &operator=(const char *pstr);
    String &operator+=(const String &rhs);
    String &operator+=(const char *pstr);
    char &operator[](size_t index);
    const char &operator[](size_t index) const;
    size_t size() const;
    const char* c_str() const;
    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>=(const String &, const String &);
    friend ostream &operator<<(ostream &os, const String &s);
    friend istream &operator>>(istream &is, String &s);
    
private:
    char *_pstr;
};

String operator+(const String &lhs, const String &rhs);
String operator+(const String &, const char *);
String operator+(const char *, const String &);

#endif