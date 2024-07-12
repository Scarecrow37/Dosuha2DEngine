#pragma once
#include "Trigger.h"

namespace Input
{
    class Press : public Trigger
    {
    public:
        void Update(float deltaTime) override;
    };
}
