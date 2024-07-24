#pragma once
#include "../Base/Base.h"

namespace Input::Trigger
{
    class Down : public Base
    {
    public:
        void Update(float deltaTime) override;
    };
}
