#pragma once
#include "../Trigger/Trigger.hpp"

namespace Input::Trigger
{
    class ChordAction : public Trigger, public IChordAction
    {
    public:
        void Update(float deltaTime) override;
    };
}
