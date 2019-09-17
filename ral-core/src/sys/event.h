#pragma once

#include "../init/macros.h"

namespace RALengine
{
    namespace sys
    {
        enum RAL_API EventCategory
        {
            None = 0,
            EventCategoryApplication    = BIT(0),
            EventCategoryWindow         = BIT(1),
            EventCategoryInput          = BIT(2),
            EventCategoryKey            = BIT(3),
            EventCategoryMouse          = BIT(4),
            EventCategoryMouseButton    = BIT(5)
        };

        enum class RAL_API EventType
        {
            None,
            AppBegin, AppTick, AppExit,
            WindowResize, WindowClose,
            Key, KeyPressed, KeyReleased,
            Mouse, MouseScroll, MouseMove,
            MouseButton, MouseButtonPressed, MouseButtonReleased
        };

        #define DECLARE_EVENT_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
                                        virtual EventType GetType() const override { return GetStaticType(); }\
                                        virtual const char* GetName() const override { return #type; }
        
        #define DECLARE_EVENT_CATEGORY(category) virtual unsigned int GetCategoryFlags() const override { return category; }

        class RAL_API Event
        {
            friend class EventDispatcher;
        public:
            virtual EventType GetType() const = 0;
            virtual unsigned int GetCategoryFlags() const = 0;
            virtual const char* GetName() const = 0;

            virtual const char* ToString() const { return GetName(); }

        private:
            bool m_dispatched;
        };
    }
}