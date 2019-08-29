#include <iostream>

#include "application.h"

namespace RALengine
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::run()
    {
        std::cout << "Welcome to RALengine!" << std::endl;
    }
}