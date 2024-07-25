#include "pch.h"
#include "MappingContext.h"

void Input::MappingContext::Update(const float deltaTime)
{
    std::ranges::for_each(_actions, [deltaTime](IAction* action) { action->Update(deltaTime); });
}
