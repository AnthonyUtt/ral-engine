#pragma once

#include "../init/macros.h"
#include "event.h"
#include "observer.h"

#define DEFAULT_SIZE 100

namespace RALengine
{
    namespace sys
    {
        class RAL_API EventDispatcher
        {
        public:
            EventDispatcher();
            ~EventDispatcher();

            void Register(Observer *o);
            void Dispatch(Event *e);

        private:
            Observer **m_observers;
            int m_size;
        };

        class RAL_API EventQueue
        {
        public:
            static EventQueue* GetInstance(unsigned int size=DEFAULT_SIZE);

            ~EventQueue();

            static void Run(unsigned int size=DEFAULT_SIZE);

            void RegisterWithDispatch(Observer *o);
            void OnTick();
            void Stop() { m_shouldStop = true; }

            void push(Event *pEvent);
            Event* pop();
            void printQueue() const;
            unsigned int size() const;
        
        protected:
            explicit EventQueue(unsigned int size);
            bool ShouldStop() const { return m_shouldStop; }

        private:
            static EventQueue* m_pInstance;

            unsigned int m_size;
            int m_head, m_tail;
            Event **m_queue;
            EventDispatcher m_dispatch;
            bool m_shouldStop;
        };

        static void sleep(unsigned int milliseconds);
    }
}