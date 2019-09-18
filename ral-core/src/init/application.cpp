#include <ral-log.h>

#include "application.h"
#include "../sys/eventqueue.h"
#include "../sys/applicationevent.h"
#include "../sys/testobserver.h"

#include <pthread.h>
#include <thread>

namespace RALengine
{
    Application::Application()
    {
        init();
    }

    Application::~Application()
    {
    }

    void Application::init()
    {
        eventThread = new std::thread(sys::EventQueue::Run, 100);
    }

    void Application::run()
    {
        LOG_INFO("Welcome to RALengine!");

        sys::EventQueue::GetInstance()->Stop();

        eventThread->join();
    }
}