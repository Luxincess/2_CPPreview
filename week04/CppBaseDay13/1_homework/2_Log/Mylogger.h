#ifndef __MYLOGGER_H__
#define __MYLOGGER_H__

#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <string.h>
using namespace log4cpp;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

#define prefix(msg) (string(__FILE__) + string(": ") \
                 + string(__FUNCTION__) + string(": ") \
                 + string(to_string(__LINE__)) + string(": ") \
                 + msg).c_str()

class Mylogger //单例模式，一个类只能创建一个对象
{
public:
    static Mylogger *getInstance();
    void destroy();

    void warn(const char *msg);
    void error(const char *msg);
    void debug(const char *msg);
    void info(const char *msg);
private:
    Mylogger();
    ~Mylogger();
private:
    static Mylogger *_pInstance;
    Category &_root;
};

#define logError(msg) Mylogger::getInstance()->error(prefix(msg))
#define logWarn(msg) Mylogger::getInstance()->warn(prefix(msg))
#define logInfo(msg) Mylogger::getInstance()->info(prefix(msg))
#define logDebug(msg) Mylogger::getInstance()->debug(prefix(msg))
#endif
