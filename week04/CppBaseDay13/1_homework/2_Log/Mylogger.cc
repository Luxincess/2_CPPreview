#include "Mylogger.h"

Mylogger *Mylogger::_pInstance = nullptr;

Mylogger *Mylogger::getInstance()
{
    if(nullptr == _pInstance)
    {
        _pInstance = new Mylogger();
    }
    return _pInstance;
}

void Mylogger::destroy()
{
    if(_pInstance)
    {
        delete _pInstance;
        _pInstance = nullptr;
    }
}

void Mylogger::warn(const char *msg)
{
    _root.warn(msg);
}

void Mylogger::error(const char *msg)
{
    _root.error(msg);
}

void Mylogger::debug(const char *msg)
{
    _root.debug(msg);
}

void Mylogger::info(const char *msg)
{
    _root.info(msg);
}

Mylogger::Mylogger()
: _root(Category::getRoot().getInstance("MyCat"))
{
    cout << "Mylogger::Mylogger()" << endl;

    //日志的格式
    PatternLayout *ppl = new PatternLayout();
    ppl->setConversionPattern("%d [%p] %c %m %n");
    PatternLayout *ppl2 = new PatternLayout();
    ppl2->setConversionPattern("%d [%p] %c %m %n");

    //日志的输出目的地
    OstreamAppender *poa = 
        new OstreamAppender("OstreamAppender", &cout); 
    poa->setLayout(ppl);
    FileAppender *pfa =
        new FileAppender("FileAppender", "MyLog.txt");
    pfa->setLayout(ppl2);

    //日志的记录器 添加目的地
    _root.setAppender(poa);
    _root.setAppender(pfa);

    //日志的优先级
    _root.setPriority(Priority::DEBUG);
}

Mylogger::~Mylogger()
{
    cout << "Mylogger::~Mylogger()" << endl;
}
