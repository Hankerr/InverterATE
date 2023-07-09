#pragma once
#include "IInstrument.h"

#include <map>
#include <memory>
#include <mutex>

static std::shared_ptr<IInstrManager> g_InstrManager = nullptr;
static std::once_flag singletonFlag;

class IInstrManager :
    public IInstr
{
public:
    static std::shared_ptr<IInstrManager> GetInstance();

    ~IInstrManager();
private:
    // 禁止外部构造
    IInstrManager() = default;;

    // 禁止外部拷贝构造
    IInstrManager(const IInstrManager& signal) = delete;

    // 禁止外部赋值操作
    const IInstrManager& operator=(const IInstrManager& signal) = delete;
public:
    void SetInstrByName(string InstrName);
    IInstr* GetInstrByName(string InstrName);
};

