#pragma once
#include "CInstrument.h"

class Imp_PW8001 :
    public CInstrument
{
public:
    Imp_PW8001();
    ~Imp_PW8001();
    virtual string InquireVolt();
};

