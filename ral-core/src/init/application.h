#pragma once

#include "macros.h"
#include <pthread.h>
#include <thread>

namespace RALengine
{
    class RAL_API Application
    {
    public:
        Application();
        virtual ~Application();
        void init();
        void run();

    private:
        std::thread *eventThread;
    };

    // To be defined in client
    Application* CreateApplication();
}