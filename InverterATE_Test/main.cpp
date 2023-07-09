#include <iostream>
#include <ctime>
#include <iomanip>

#include <windows.h>


#include "../InverterATE_dll/IInstrument.h"
//#include "../InverterATE_dll/Imp_PW8001.h"

#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/loglevel.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/initializer.h>
#include <log4cplus/fileappender.h>

using namespace log4cplus;
using namespace log4cplus::helpers;

using namespace std;

static Logger g_DebugLogger = Logger::getInstance("log");

void printMsg(string fBsn, string msg) {
    static Initializer initializer;

    time_t now = time(NULL);
    tm* ptrTm_t = localtime(&now);
    stringstream ssNowTimeStream;
    ssNowTimeStream.clear();
    ssNowTimeStream << setw(2) << left << ptrTm_t->tm_hour << setw(2) << left << ptrTm_t->tm_min << setw(2) << left << ptrTm_t->tm_sec;
    string logPath = "./log/" + fBsn + "_" + ssNowTimeStream.str() + "_DEBUG.log";

    SharedAppenderPtr _append(new FileAppender(logPath, std::ios_base::ate, true, true));
    _append->setName("file_log_test");

    std::string pattern = "%D{%Y-%m-%d %H:%M:%S} %m%n";
    _append->setLayout(std::auto_ptr<Layout>(new PatternLayout(pattern)));

    g_DebugLogger.addAppender(_append);

    LOG4CPLUS_DEBUG(g_DebugLogger, msg);
}

int main() {
    //string bsn = "1111111111111";
    ///*log activity*/
    //for (int i = 0; i < 5; ++i) {
    //    printMsg(bsn, "Enteringloop#");
    //}


    auto pIns = IInstrManager::GetInstance();

    system("pause");
}