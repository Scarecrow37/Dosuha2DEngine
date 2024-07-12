#pragma once


namespace Input
{
    struct IListener;

    class Trigger
    {
        virtual void Update(float deltaTime) = 0;

    protected:
        IListener* _listener;
    };
}
