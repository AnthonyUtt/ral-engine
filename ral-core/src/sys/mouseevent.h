#pragma once

#include "../init/macros.h"
#include "event.h"

namespace RALengine
{
    namespace sys
    {
        class RAL_API MouseEvent : public Event
        {
        public:
            DECLARE_EVENT_CATEGORY(EventCategoryInput | EventCategoryMouse);
            DECLARE_EVENT_TYPE(Mouse);
        
        protected:
            MouseEvent();
        };

        class RAL_API MouseScrollEvent : public MouseEvent
        {
        public:
            MouseScrollEvent(double x, double y);
            DECLARE_EVENT_TYPE(MouseScroll);

            double GetXValue() const { return mx; }
            double GetYValue() const { return my; }

        private:
            double mx, my;
        };

        class RAL_API MouseMoveEvent : public MouseEvent
        {
        public:
            MouseMoveEvent(double x, double y) : mx(x), my(y) {};

            double GetXValue() const { return mx; }
            double GetYValue() const { return my; }

        private:
            double mx, my;
        };

        class RAL_API MouseButtonEvent : public MouseEvent
        {
        public:
            DECLARE_EVENT_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton);
            DECLARE_EVENT_TYPE(MouseButton);

            int GetButton() const { return m_button; }

        protected:
            MouseButtonEvent();
            int m_button;
        };

        class RAL_API MouseButtonPressedEvent : public MouseButtonEvent
        {
        public:
            MouseButtonPressedEvent(int button, bool repeat) : m_repeat(repeat) { m_button = button; }
            DECLARE_EVENT_TYPE(MouseButtonPressed);

        private:
            bool m_repeat;
        };

        class RAL_API MouseButtonReleasedEvent : public MouseButtonEvent
        {
        public:
            MouseButtonReleasedEvent(int button) { m_button = button; }
            DECLARE_EVENT_TYPE(MouseButtonReleased);
        };
    }
}