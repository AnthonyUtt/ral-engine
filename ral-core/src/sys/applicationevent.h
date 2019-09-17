#pragma once

#include "../init/macros.h"
#include "event.h"

namespace RALengine
{
    namespace sys
    {
        class RAL_API AppBeginEvent : public Event
        {
        public:
            DECLARE_EVENT_CATEGORY(EventCategoryApplication);
            DECLARE_EVENT_TYPE(AppBegin);
        };

        class RAL_API AppTickEvent : public Event
        {
        public:
            DECLARE_EVENT_CATEGORY(EventCategoryApplication);
            DECLARE_EVENT_TYPE(AppTick);
        };

        class RAL_API AppExitEvent : public Event
        {
            DECLARE_EVENT_CATEGORY(EventCategoryApplication);
            DECLARE_EVENT_TYPE(AppExit);
        };
    }
}