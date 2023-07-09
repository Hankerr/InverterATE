#pragma once
#include "IInstrument.h"

class CInstr :
    public IInstr
{
public:
    virtual ViStatus IInstrOpen();
    virtual ViStatus IInstrClose();
    virtual string InquireVolt();
};

