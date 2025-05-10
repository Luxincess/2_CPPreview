#include "Mylogger.h"

inline string connect(const string &msg)
{
    string tmp = string(__FILE__) + string(": ")
                 + string(__FUNCTION__) + string(": ")
                 + string(to_string(__LINE__)) + string(": ")
                 + msg;
    return tmp;
}

void test()
{
    Mylogger *plog = Mylogger::getInstance();
    plog->error("this is an error msg");
    plog->destroy();
    plog = nullptr;
}

void test1()
{
    Mylogger::getInstance()->error("this is an error msg");
    Mylogger::getInstance()->warn("this is an warn msg");
    Mylogger::getInstance()->info("this is an info msg");
    Mylogger::getInstance()->debug("this is an debug msg");
    Mylogger::getInstance()->destroy();
}

void test2()
{
    cout << __FILE__ << " "
         << __FUNCTION__ << " "
         << __LINE__ << endl;
}

void test3()
{
    Mylogger::getInstance()->error(prefix("this is an error msg"));
    Mylogger::getInstance()->info(prefix("this is an info msg"));
}

void test4()
{
    //达到了类似printf打印输出的效果
    logError("this is an error msg");
    logWarn("this is a warn msg");
    logInfo("this is a info msg");
    logDebug("this is a debug msg");

}

int main(int argc, char* argv[])
{
    test4();
    return 0;
}

