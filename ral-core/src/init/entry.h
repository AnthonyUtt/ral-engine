#pragma once

#include "application.h"

extern RALengine::Application* RALengine::CreateApplication();

#if defined WIN32 || defined __CYGWIN__
int main (int argc, char** argv)
{
    auto app = RALengine::CreateApplication();
    app->run();
    delete app;
}
#else
int main (int argc, char** argv)
{
    RALengine::Application* app = RALengine::CreateApplication();
    app->run();
    delete app;
}
#endif