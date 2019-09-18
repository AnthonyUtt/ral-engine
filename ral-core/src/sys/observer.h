#pragma once

#include "../init/macros.h"
#include "event.h"

namespace RALengine
{
    namespace sys
    {
        class Observer
        {
        public:
            virtual void OnNotify(Event *e) const = 0;
            virtual unsigned int GetCategoryFlags() const = 0;
        };
    }
}