#pragma once
#include "IInstrument.h"

class CInstrument :
    public IInstrument
{
public:
    virtual ViStatus IInstrumentOpen();
    virtual ViStatus IInstrumentClose();
    virtual string InquireVolt();
};

