#include "pch.h"
#include "Action.h"

Input::Action::Action(const std::shared_ptr<Action_>& action)
    : _action(action)
{
}


void Input::Action::AddListener(const TriggerState state, Listener listener)
{
}
