#include <iostream>

#include <windows.h>

#include "../InverterATE_dll/IInstrument.h"
#include "../InverterATE_dll/Imp_PW8001.h"

#include <log4cplus/logger.h>
#include "log4cplus/consoleappender.h"
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>


using namespace log4cplus;
using namespace log4cplus::helpers;

using namespace std;

int main() {
    PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("log.properties"));
    Logger logger = log4cplus::Logger::getRoot();

    LOG4CPLUS_INFO(logger, LOG4CPLUS_TEXT("LOG4CPLUS_INFO1"));
    cout << "INFO1" << endl;
    Sleep(12000);
    LOG4CPLUS_INFO(logger, LOG4CPLUS_TEXT("LOG4CPLUS_INFO2"));

    LOG4CPLUS_ERROR(logger, LOG4CPLUS_TEXT("LOG4CPLUS_ERROR1"));

    cout << "ERROR1" << endl;
    Sleep(12000);
    LOG4CPLUS_ERROR(logger, LOG4CPLUS_TEXT("LOG4CPLUS_ERROR2"));


    cout << "Finish" << endl;

    // 输出到控制台
    //log4cplus::Logger loggerConsole = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("console"));
    //LOG4CPLUS_INFO(loggerConsole, LOG4CPLUS_TEXT("console output..."));

    system("pause");
}