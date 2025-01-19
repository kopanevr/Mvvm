#include "view.hpp"

#include <string>
#include <iostream>

View::View(ViewModel* pViewModel)
    :   m_pViewModel(pViewModel)
{
    m_pViewModel->subcribeOnNameChanged([this]()
    {
        update();
    });
    m_pViewModel->subcribeOnAgeChanged([this]()
    {
        update();
    });
}

View* View::getInstance(ViewModel* pViewModel)
{
    static View sInstace(pViewModel);

    return &sInstace;
}

void View::update()
{
    std::cout << "Name: " << m_pViewModel->getName() << "\n";
    std::cout << "Age: " << m_pViewModel->getAge() << "\n";
}

void View::printMenu()
{
    std::cout << "\nMenu:\n";
    std::cout << "1. Set Name\n";
    std::cout << "2. Set Age\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int View::processInput()
{
    int choice = -1;

    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        std::string name;

        std::cout << "Name: ";

        std::cin >> name;

        std::cout << "\n";

        m_pViewModel->setName(name);

        break;
    }
    case 2:
    {
        uint8_t age = 0U;

        std::cout << "Age: ";

        std::cin >> age;

        std::cout << "\n";

        m_pViewModel->setAge(age);

        break;
    }
    case 0:
        break;
    default:
        break;
    }

    return choice;
}

void View::startUp()
{
    update();

    do
    {
        printMenu();
    }
    while (processInput() != 0);
}
