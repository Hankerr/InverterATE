#pragma once

//#include <log4cplus/log4cplus.h>

#include <string>

#include "NI/Include/visatype.h"
#include "NI/Include/visa.h"

using namespace std;

class IInstrument
{
public:
    virtual ViStatus IInstrumentOpen() = 0;
    virtual ViStatus IInstrumentClose() = 0;
    virtual string InquireVolt();
};

