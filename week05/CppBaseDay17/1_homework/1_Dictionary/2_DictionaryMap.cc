#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;

//替换vector为map,map的底层实现为红黑树，查找效率更高

//实现功能：使用一个vector来存储词典，词典中每一个元素为： 单词：数目   的形式
//使用vector来存储，vector中的一个元素要存储两个属性，使用结构体struct来存储 单词:数目
//待处理的文本事先已经经过了特殊处理 只有隔开的数字以及单词 没有标点符号 降低了难度
//思路：
/*
首先需要处理文本，用一个文件输入流对象来接这个文本，使用getline函数来一行一行地读取
对于读取到的每一行，使用一个字符串输入流对象来接这一行内容，然后依次处理这一行中的每一个单词或数字
处理好之后插入到词典中（判断是否已经在词典中）
最后将得到的结果输出到指定的文件中
*/

#if 0
struct word_num
{
    string _word;
    int _count;
    word_num(string word, int count)
    : _word(word)
    , _count(count)
    {

    }
};
#endif

class Dictionary
{
public:
    void read(const string &filename); //读取初始文本
    void store(const string &filename); //存储生成好的词典
private:
    string dealWord(const string &word); //处理每一个单词
    void insert(const string &word);      //将处理好的单词插入到词典
};

//vector<word_num> word_vec;
map<string, int> dictMap;

void Dictionary::read(const string &filename)
{
    ifstream ifs(filename);
    string line;
    while(getline(ifs, line))
    {
        istringstream iss(line);
        string temp;
        while(iss >> temp)
        {
            string word = dealWord(temp);
            insert(word);
        }
    }
}

void Dictionary::store(const string &filename)
{
    ofstream ofs(filename);
    for(auto it = dictMap.begin(); it != dictMap.end(); ++it)
    {
        ofs << it->first << " : " << it->second << endl;
    }
}

string Dictionary::dealWord(const string &word)
{
    for(int i = 0; i < word.length(); ++i)
    {
        if(!isalpha(word[i]))
        {
            return string();  
        }
    }
    return word;
}

void Dictionary::insert(const string &word)
{
    if(word == string()) return;    //遇到空字符串直接返回
    if(dictMap.find(word) != dictMap.end())
    {
        ++ dictMap[word];
    }
    else
    {
        dictMap[word] = 1;
    }
    return;
}

void test()
{
    Dictionary dict;
    cout << "begin read..." << endl;
    dict.read("The_Holy_Bible.txt");
    cout << "end read..." << endl;
    cout << endl;
    cout << "begin store..." << endl;
    dict.store("generate_dictMap.txt");
    cout << "end store..." << endl;
}

int main()
{
    test();
    return 0;
}

