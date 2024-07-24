#pragma once
#include "../State/State.h"


namespace Input::Trigger
{
    class Base
    {
    public:
        Base() = default;
        Base(const Base& other) = default;
        Base(Base&& other) noexcept = default;
        Base& operator=(const Base& other) = default;
        Base& operator=(Base&& other) noexcept = default;
        virtual ~Base() = default;

        virtual void Update(float deltaTime) = 0;

    protected:
        State _triggered;
        State _started;
        State _onGoing;
        State _completed;
        State _canceled;
    };
}
