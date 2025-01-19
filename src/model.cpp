#include "Model.hpp"

Model::Model(std::string name, uint8_t age)
    :   m_Name(name),
        m_Age(age)
{
}

Model* Model::getInstance(std::string name, uint8_t age)
{
    static Model sInstance(name, age);

    return &sInstance;
}
