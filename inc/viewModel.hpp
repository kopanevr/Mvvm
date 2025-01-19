#pragma once

#include <functional>

#include "Model.hpp"

class ViewModel final
{
private:
    Model* m_pModel = nullptr;

    std::vector<std::function<void()>> m_NameChanegedCallbacks;
    std::vector<std::function<void()>> m_AgeChanegedCallbacks;

    //

    ViewModel(Model* pModel);

    ViewModel(const ViewModel&) = delete;
    ViewModel& operator=(const ViewModel&) = delete;

    void onNameChanged();
    void onAgeChanged();
public:
    ~ViewModel() = default;

    static ViewModel* getInstance(Model* pModel);

    //

    std::string getName() const noexcept;
    uint8_t getAge() const noexcept;

    void setName(const std::string& name) noexcept;
    void setAge(uint8_t age) noexcept;

    //

    // ФУНКЦИИ-ЧЛЕНЫ ДЛЯ ПОДПИСКИ НА СОБЫТИЕ
    void subcribeOnNameChanged(std::function<void()> callback);
    void subcribeOnAgeChanged(std::function<void()> callback);
};
