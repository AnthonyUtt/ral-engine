#pragma once

#include "../init/macros.h"
#include "event.h"

namespace RALengine
{
    namespace sys
    {
        class RAL_API KeyEvent : public Event
        {
        public:
            DECLARE_EVENT_CATEGORY(EventCategoryInput | EventCategoryKey);
            DECLARE_EVENT_TYPE(Key);

            virtual int GetKeyCode() const { return m_keyCode; }

        protected:
            KeyEvent();

            int m_keyCode;
        };

        class RAL_API KeyPressedEvent : public KeyEvent
        {
        public:
            KeyPressedEvent(int keyCode, bool repeat) : m_repeat(repeat) { m_keyCode = keyCode; }
            DECLARE_EVENT_TYPE(KeyPressed);

        private:
            bool m_repeat;
        };

        class RAL_API KeyReleasedEvent : public KeyEvent
        {
        public:
            KeyReleasedEvent(int keyCode) { m_keyCode = keyCode; }
            DECLARE_EVENT_TYPE(KeyReleased);
        };
    }
}