#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::cin;

class TextQuery
{
public:
    TextQuery()
    {
        //_file.resize(100);
        _file.reserve(100);
    }
    void readFile(const string &filename);
    void query(const string &word);
private:
    void processLine(string &line);
private:
    vector<string> _file;   //存储每一行的内容
    map<string, int> _dictMap; //存储单词以及对应的频率
    map<string, set<int>> _word2line; //存储单词所在的行号
};

void TextQuery::readFile(const string &filename)
{
    ifstream ifs(filename);
    //判断流的状态
    if(!ifs)
    {
        cout << "ifs open " << filename << "error" << endl;
        return;
    }
    string line;
    size_t lineNumber = 0;
    while(getline(ifs, line))
    {
        _file.push_back(line);
        processLine(line); //处理每一行
        istringstream iss(line);
        string word;
        while(iss >> word)
        {
            ++ _dictMap[word];
            _word2line[word].insert(lineNumber);
        }
        lineNumber++;
    }
    ifs.close();
}

void TextQuery::processLine(string &line)
{
    for(auto &ch : line)
    {
        if(!isalpha(ch))
        {
            ch = ' ';
        }
        else if(isupper(ch))
        {
            ch = tolower(ch);
        }
    }
}

void TextQuery::query(const string &word)
{
    cout << word << " occurs " << _dictMap[word] << (_dictMap[word] > 1? " times " : " time ") << endl;
    auto Line = _word2line[word];
    // cout << endl;
    // cout << _file[0] << endl;
    // cout << endl;
    for(auto &lineNum : Line)
    {
        cout << lineNum+1 << " : " << _file[lineNum] << endl;
    }
}

void test()
{
    TextQuery tq;
    tq.readFile("china_daily.txt");
    cout << "pls input a query word : " << endl;
    string word;
    while(cin >> word)
    {
        tq.query(word);
    }
}

int main()
{
    test();
    return 0;
}

