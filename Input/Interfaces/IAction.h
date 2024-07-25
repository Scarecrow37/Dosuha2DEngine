#pragma once

namespace Input
{
    struct IAction
    {
        IAction() = default;
        IAction(const IAction&) = default;
        IAction& operator=(const IAction&) = default;
        IAction(IAction&&) = default;
        IAction& operator=(IAction&&) = default;
        virtual ~IAction() = default;

        virtual void Update(float deltaTime) = 0;
        virtual void AddListener(TriggerState state, Listener listener) = 0;
    };
}
