#include "pch.h"
#include "Action.h"

void Input::Action::Update(float deltaTime)
{
    std::ranges::for_each(_triggers, [deltaTime](Trigger::ITrigger* trigger) { trigger->Update(deltaTime); });
}

void Input::Action::AddListener(const TriggerState state, Listener listener)
{
    _states[state].AddListener(listener);
}
