#include "pch.h"
#include "State.h"

void Input::Trigger::State::AddListener(const Listener& listener)
{
    _listeners.push_back(std::move(listener));
}

void Input::Trigger::State::Execute(const Value& value)
{
    std::ranges::for_each(_listeners, [&](const Listener& listener) { listener(value); });
}
