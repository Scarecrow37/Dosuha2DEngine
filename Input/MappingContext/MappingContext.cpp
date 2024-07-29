#include "pch.h"
#include "MappingContext.h"
#include "../Action/Action_.h"

void Input::MappingContext::Update(const float deltaTime)
{
    std::ranges::for_each(_actions, [deltaTime](auto& action) { action.second->Update(deltaTime); });
}

void Input::MappingContext::Reset()
{
    std::ranges::for_each(_actions, [](auto& action) { action.second->Reset(); });
}

Input::Action* Input::MappingContext::CreateAction(const std::wstring_view& name)
{
    if (_actions.contains(name)) ThrowRuntimeErrorIf<Exception::RuntimeError>()(true, L"Action already exists.");
    _actions[name] = std::make_shared<Action_>();
    return new Action(_actions[name]);
}

Input::Action* Input::MappingContext::GetAction(const std::wstring_view& name)
{
    if (!_actions.contains(name)) ThrowRuntimeErrorIf<Exception::RuntimeError>()(true, L"Action does not exist.");
    return new Action(_actions[name]);
}
