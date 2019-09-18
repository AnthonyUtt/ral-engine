#include "eventqueue.h"
#include <iostream>
#include <cstring>

namespace RALengine
{
    namespace sys
    {
        EventQueue* EventQueue::m_pInstance = nullptr;

        EventDispatcher::EventDispatcher()
        {
            m_observers = (Observer**) malloc(sizeof(Observer*));
            m_observers[0] = nullptr;
            m_size = 1;
        }

        EventDispatcher::~EventDispatcher()
        {
        }

        void EventDispatcher::Register(Observer *o)
        {
            bool found = false;
            for (int i = 0; i < m_size; i++)
            {
                if (m_observers[i] == o)
                    found = true;
            }

            if (!found)
            {
                //first entry edge case
                if (m_observers[0] == nullptr)
                {
                    m_observers[0] = o;
                }
                else
                {
                    Observer** newpa = (Observer**) malloc((m_size + 1) * sizeof(Observer*));
                    memcpy(newpa, m_observers, m_size * sizeof(Observer*));
                    delete m_observers;
                    m_observers = newpa;
                    m_observers[m_size] = o;
                    m_size++;
                }
            }
        }

        void EventDispatcher::Dispatch(Event *e)
        {
            for (int i = 0; i < m_size; i++)
            {
                if (m_observers[i]->GetCategoryFlags() & e->GetCategoryFlags())
                {
                    m_observers[i]->OnNotify(e);
                }
            }
        }

        EventQueue* EventQueue::GetInstance(unsigned int size)
        {
            static EventQueue instance(size);
            
            return &instance;
        }

        EventQueue::EventQueue(unsigned int size) : m_size(size)
        {
            //resizing array
            m_queue = (Event**) malloc(m_size * sizeof(Event*));
            for (int i = 0; i < m_size; i++)
            {
                m_queue[i] = nullptr;
            }

            m_head = m_tail = 0;

            EventDispatcher d;
            m_dispatch = d;

            m_shouldStop = false;
        }

        EventQueue::~EventQueue()
        {
        }

        void EventQueue::Run(unsigned int size)
        {
            EventQueue* q = GetInstance(size);

            while(!q->ShouldStop())
            {
                q->OnTick();
                sleep(100);
            }
        }

        void EventQueue::RegisterWithDispatch(Observer *o)
        {
            m_dispatch.Register(o);
        }

        void EventQueue::OnTick()
        {
            Event *e = pop();
            if (e != nullptr)
            {
                m_dispatch.Dispatch(e);
            }
        }

        void EventQueue::push(Event *pEvent)
        {
            if (m_queue[m_tail] != nullptr)
                return;
                
            m_queue[m_tail] = pEvent;
            m_tail = (m_tail + 1) % m_size;
        }

        Event* EventQueue::pop()
        {
            if (m_queue[m_head] == nullptr)
                return nullptr;

            Event *retVal = m_queue[m_head];
            m_queue[m_head] = nullptr;
            m_head = (m_head + 1) % m_size;

            return retVal;
        }

        void EventQueue::printQueue() const
        {
            for (int i = 0; i < m_size; i++)
            {
                std::cout << "Index " << i << ": ";
                if (m_queue[i] == nullptr)
                    std::cout << "NULL";
                else
                    std::cout << m_queue[i]->ToString();

                if (i == m_head)
                    std::cout << "\tHEAD";
                if (i == m_tail)
                    std::cout << "\tTAIL";
                
                std::cout << std::endl;
            }
        }

        unsigned int EventQueue::size() const
        {
            return m_size;
        }

        static void sleep(unsigned int milliseconds)
        {
            struct timespec req = {0};
            req.tv_sec = 0;
            req.tv_nsec = milliseconds * 1000000L;
            nanosleep(&req, (struct timespec *)NULL);
        }
    }
}