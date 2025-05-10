#include <iostream>
#include <string.h>
using namespace std;

class Student
{
public:
    Student(const char *name, int id);
    void print() const;
    static void *operator new(size_t sz);
    static void operator delete(void *ptr);
    void destroy(Student *pst);
private:
    ~Student();
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

void Student::destroy(Student *pst)
{
    if(pst)
    {
        delete pst;
        pst = nullptr;
    }
}
void test()
{
    /* Student stu2("lfc",190400307 ); */
    /* stu2.print(); */
    Student *stu = new Student("lsx",190400308);//new调用一次operator new
    stu->print();
    stu->destroy(stu);
    stu = nullptr;

    /* delete stu; //这里的delete调用一次operator delete */
    /* stu = nullptr; */

}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

