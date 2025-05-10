#include <iostream>
#include <string.h>
using namespace std;

/* void *operator new(size_t sz); */
/* void operator delete(void *ptr); */
class Student
{
public:
    Student(const char *name, int id);
    void print() const;
    ~Student();
private://operator new/delete私有化，只能创建栈对象，不能创建堆对象
    static void *operator new(size_t sz);
    static void operator delete(void *ptr);
private:
    char *_name;
    int _id;
};

void *Student::operator new(size_t sz)
{
    cout << "void *operator new(size_t)" << endl;
    void *pret;
    pret = malloc(sz);
    return pret;
}

void Student::operator delete(void *ptr)
{
    cout << "void operator delete(void *)" <<endl;
    free(ptr);
}

Student::Student(const char *name, int id)
: _name(new char[strlen(name) + 1]()) //这里的new会调用一次operator new
, _id(id)
{
    cout << "Student(const char *, int)" << endl;
    strcpy(_name, name);
}

void Student::print() const
{
    cout << "name = " << _name << endl
         << "id = " << _id << endl;
}

Student::~Student()
{
    cout << "~Student()" <<endl;
    if(_name)
    {
        delete []_name; //这里的delete会调用一次operator delete
        _name = nullptr;
    }
}
void test()
{
    /* Student *stu = new Student("lsx",190400308);//new调用一次operator new */
    /* stu->print(); */
    /* delete stu; //这里的delete调用一次operator delete */
    /* stu = nullptr; */
    Student stu2("lfc",190400307);
    stu2.print();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

