#pragma once

namespace Input::Trigger
{
    class State
    {
        using Listener = std::function<void(const Value&)>;

    public:
        void AddListener(const Listener& listener);
        void Execute(const Value& value);

    private:
        std::vector<Listener> _listeners;
    };
}
