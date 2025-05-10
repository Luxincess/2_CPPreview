#include "1_dict.h"

string Dictionary::dealWord(const string &word)
{
   for(size_t idx = 0; idx != word.size(); ++idx)
   {
        if(!isalpha(word[idx])) return string();
   }
   return word;
}

void Dictionary::insert(const string &word)
{
    if(word == string())
        return;
    size_t idx;
    for(idx = 0; idx != _dict.size(); ++idx)
    {
        if(_dict[idx]._word == word)
        {
            _dict[idx]._frequency ++;
            break;
        }
    }
    if(idx == _dict.size())
    {
        _dict.push_back(Record(word, 1));
    }
}
void Dictionary::read(const string &filename)
{
    ifstream ifs(filename);
    if(!ifs.good())
    {
        cout << "ifstream is not good" << endl;
        return;
    }
    string line;
    while(getline(ifs, line))
    {
       //用字符串流来接line
       istringstream iss(line);
       //得到一个一个单独的单词
       string word;
       while(iss >> word)
       {
           string newWord = dealWord(word);
           insert(newWord);
       }
       //然后使用dealWord来处理单词 得到处理好的单词
       //最后使用insert将处理好的单词插入到_dict中
    }
    ifs.close();
}

void Dictionary::store(const string &filename)
{
    ofstream ofs(filename);
    if(!ofs.good())
    {
        cerr << "ofstream is not good" << endl;
        return;
    }
    for(size_t i = 0; i < _dict.size(); ++i)
    {
        ofs << _dict[i]._word 
            << "      "
            << _dict[i]._frequency 
            << endl;
    }
    ofs.close();
}


