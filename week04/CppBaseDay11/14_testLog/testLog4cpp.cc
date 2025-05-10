#include <iostream>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>

using std::cout;
using std::endl;
using namespace log4cpp;
void test()
{
    //布局
    BasicLayout *pbl = new BasicLayout();

    //输出器
    OstreamAppender *poa = new OstreamAppender("ostreamAppender",&cout);
    poa->setLayout(pbl);//为输出器指定布局，也就是指定输出格式
    //记录器
    Category &root = Category::getRoot();
    root.addAppender(poa);
    //为日志设置过滤器
    root.setPriority(Priority::ERROR);

    root.emerg("This is an emerg message");
    root.fatal("This is an fatal message");
    root.alert("This is an alert message");
    root.crit("This is an crit message");
    root.error("This is an error message");
    root.notice("This is an notice message");
    root.debug("This is an debug message");







}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

