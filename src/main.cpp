#include "model.hpp"
#include "viewModel.hpp"
#include "view.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] const char** argv)
{
    Model* pModel = Model::getInstance();

    ViewModel* pViewModel = ViewModel::getInstance(pModel);

    View* pView = View::getInstance(pViewModel);

    pView->startUp();

    return 0;
}
