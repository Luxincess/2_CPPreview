#ifndef __DICT_H__
#define __DICT_H__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctype.h>
#include <sstream>
using namespace std;

struct Record
{
    Record(const string &word, int frequency)
    : _word(word)
    , _frequency(frequency)
    {}
    
    string _word;
    int _frequency;
};

class Dictionary
{
public:
    void read(const string &filename);
    string dealWord(const string &word);
    void insert(const string &word);
    void store(const string &filename);
private:
    vector<Record> _dict;
};


#endif
