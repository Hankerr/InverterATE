#include <iostream>

#include "../InverterATE_dll/IInstrument.h"
#include "../InverterATE_dll/Imp_PW8001.h"

using namespace std;

int main() {
    cout << "Test" << endl;

    IInstrument* iInstrument = new Imp_PW8001();

    cout << iInstrument->InquireVolt() << endl;

    system("pause");
}