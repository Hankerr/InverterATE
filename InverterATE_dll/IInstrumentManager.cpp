#include "IInstrumentManager.h"

inline std::shared_ptr<IInstrManager> IInstrManager::GetInstance()
{
    std::call_once(singletonFlag, [&]() {
        g_InstrManager = std::shared_ptr<IInstrManager>(new IInstrManager());
        });
    return g_InstrManager;
}

IInstrManager::~IInstrManager()
{
    if (g_InstrManager != nullptr)
    {
        delete g_InstrManager;
        g_InstrManager = nullptr;
    }
}
