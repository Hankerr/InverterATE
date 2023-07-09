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
    // ��ֹ�ⲿ����
    IInstrManager() = default;;

    // ��ֹ�ⲿ��������
    IInstrManager(const IInstrManager& signal) = delete;

    // ��ֹ�ⲿ��ֵ����
    const IInstrManager& operator=(const IInstrManager& signal) = delete;
public:
    void SetInstrByName(string InstrName);
    IInstr* GetInstrByName(string InstrName);
};

