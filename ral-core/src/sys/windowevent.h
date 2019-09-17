#pragma once

#include "../init/macros.h"
#include "event.h"

namespace RALengine
{
    namespace sys
    {
        class RAL_API WindowResizeEvent : public Event
        {
        public:
            WindowResizeEvent(int x, int y) : mx(x), my(y) {};

            DECLARE_EVENT_CATEGORY(EventCategoryApplication);
            DECLARE_EVENT_TYPE(WindowResize);
            int GetXValue() const { return mx; }
            int GetYValue() const { return my; }
        
        private:
            int mx, my;
        };

        class RAL_API WindowCloseEvent : public Event
        {
        public:
            DECLARE_EVENT_CATEGORY(EventCategoryApplication);
            DECLARE_EVENT_TYPE(WindowClose);
        };
    }
}