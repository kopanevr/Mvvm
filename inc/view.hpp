#pragma once

#include "ViewModel.hpp"

class View final
{
private:
    ViewModel* m_pViewModel = nullptr;

    //

    View(ViewModel* pViewModel);

    View(const View&) = delete;
    View& operator=(const View&) = delete;

    void update();
    void printMenu();
    int processInput();
public:
    ~View() = default;

    static View* getInstance(ViewModel* pViewModel);

    void startUp();
};
