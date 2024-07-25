#pragma once

namespace Input::Trigger
{
    class Down : public ITrigger
    {
    public:
        void Update(float deltaTime) override;
    };
}
