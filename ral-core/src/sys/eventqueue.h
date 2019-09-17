#pragma once

#include "../init/macros.h"
#include "event.h"

namespace RALengine
{
    namespace sys
    {
        class RAL_API EventQueue
        {
        public:
            explicit EventQueue(size_t size);
            ~EventQueue();

            void push(Event *pEvent);
            Event* pop();
            void printQueue() const;
        
        private:
            unsigned int m_size;
            int m_head, m_tail;
            Event **m_queue;
        };
    }
}