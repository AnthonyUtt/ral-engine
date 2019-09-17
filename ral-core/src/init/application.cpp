#include <ral-log.h>

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
        LOG_INFO("Welcome to RALengine!");
    }
}