#include <iostream>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/SimpleLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/RollingFileAppender.hh>

using std::cout;
using std::endl;
using namespace log4cpp;
void test()
{
    //布局
    /* BasicLayout *pbl = new BasicLayout(); */
    /* SimpleLayout *psl = new SimpleLayout(); */
    PatternLayout *ppl = new PatternLayout();
    ppl->setConversionPattern("%d [%p] %c : %m%n");
    PatternLayout *ppl2 = new PatternLayout();
    ppl2->setConversionPattern("%d [%p] %c : %m%n");

    //输出器
    OstreamAppender *poa = new OstreamAppender("ostreamAppender",&cout);
    /* poa->setLayout(pbl);//为输出器指定布局，也就是指定输出格式 */
    poa->setLayout(ppl);

    /* FileAppender *pfa = new FileAppender("fileAppender","3_testlog.txt"); */
    /* pfa->setLayout(ppl2); */
    RollingFileAppender *prfa = new RollingFileAppender("file",
                                                        "4_testlog.txt",
                                                        5 * 1024,
                                                        3);
    prfa->setLayout(ppl2);


    //记录器
    Category &root = Category::getRoot().getInstance("xlsxx");
    root.addAppender(poa);
    root.addAppender(prfa);
    /* root.addAppender(pfa); */
    //为日志设置过滤器
    root.setPriority(Priority::ERROR);

    size_t idx = 40;
    while(idx > 0)
    {
        root.emerg("This is an emerg message");
        root.fatal("This is an fatal message");
        root.alert("This is an alert message");
        root.crit("This is an crit message");
        root.error("This is an error message");
        root.notice("This is an notice message");
        root.debug("This is an debug message");
        idx --;
    }
    //回收
    Category::shutdown();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

