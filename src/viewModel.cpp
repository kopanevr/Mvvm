#include "viewModel.hpp"

ViewModel::ViewModel(Model* pModel)
    :   m_pModel(pModel)
{
}

void ViewModel::onNameChanged()
{
    for (std::function<void()> const& callback : m_NameChanegedCallbacks)
    {
        callback();
    }
}

void ViewModel::onAgeChanged()
{
    for (std::function<void()> const& callback : m_AgeChanegedCallbacks)
    {
        callback();
    }
}

ViewModel* ViewModel::getInstance(Model* pModel)
{
    static ViewModel sInstance(pModel);

    return &sInstance;
}

std::string ViewModel::getName() const noexcept
{
    return m_pModel->getName();
}

uint8_t ViewModel::getAge() const noexcept
{
    return m_pModel->getAge();
}

void ViewModel::setName(const std::string& name) noexcept
{
    m_pModel->setName(name);

    // УВЕДОМЛЕНИЕ ОБ ИЗМЕНЕНИИ
    onNameChanged();
}

void ViewModel::setAge(uint8_t age) noexcept
{
    m_pModel->setAge(age);

    // УВЕДОМЛЕНИЕ ОБ ИЗМЕНЕНИИ
    onAgeChanged();
}

void ViewModel::subcribeOnNameChanged(std::function<void()> callback)
{
    m_NameChanegedCallbacks.push_back(callback);
}

void ViewModel::subcribeOnAgeChanged(std::function<void()> callback)
{
    m_AgeChanegedCallbacks.push_back(callback);
}
