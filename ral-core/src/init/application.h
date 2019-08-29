#pragma once

#include "macros.h"

namespace RALengine
{
    class RAL_API Application
    {
    public:
        Application();
        virtual ~Application();
        void run();
    };

    // To be defined in client
    Application* CreateApplication();
}