#pragma once

#include <stdint.h>

#include <string>

class Model final
{
private:
    std::string m_Name;

    uint8_t m_Age = 0U;

    //

    Model(std::string name, uint8_t age);

    Model(const Model&) = delete;
    Model& operator=(const Model&) = delete;
public:
    ~Model() = default;

    static Model* getInstance(std::string name = "", uint8_t age = 0U);

    //

    std::string getName() const noexcept
    {
        return m_Name;
    }

    uint8_t getAge() const noexcept
    {
        return m_Age;
    }

    void setName(const std::string& name) noexcept
    {
        m_Name = name;
    }

    void setAge(uint8_t age) noexcept
    {
        m_Age = age;
    }
};
