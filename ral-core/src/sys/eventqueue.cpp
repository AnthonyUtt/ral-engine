#include "eventqueue.h"
#include <iostream>

namespace RALengine
{
    namespace sys
    {
        EventQueue::EventQueue(size_t size) : m_size(size)
        {
            //resizing array
            m_queue = (Event**) malloc(size * sizeof(Event*));

            m_head = m_tail = 0;
        }

        EventQueue::~EventQueue()
        {
        }

        void EventQueue::push(Event *pEvent)
        {
            if ((m_tail + 1) % m_size == m_head)
                return;
                
            m_queue[m_tail] = pEvent;
            m_tail = (m_tail + 1) % m_size;
        }

        Event* EventQueue::pop()
        {
            if (m_head == m_tail)
                return nullptr;

            Event *retVal = m_queue[m_head];
            m_head = (m_head + 1) % m_size;

            return retVal;
        }

        void EventQueue::printQueue() const
        {
            std::cout << "Head: " << m_head << "; Tail: " << m_tail << std::endl;
            for (int i = m_head; i != m_tail; i = (i + 1) % m_size)
            {
                std::cout << "Index " << i << ": " << m_queue[i]->ToString() << std::endl;
            }
        }
    }
}