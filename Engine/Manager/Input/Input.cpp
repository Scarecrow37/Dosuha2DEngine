#include "pch.h"
#include "Input.h"

void Engine::Manager::Input::Initialize()
{
    GetInstance()->_system = std::unique_ptr<::Input::ISystem>(::Input::CreateSystem());
}

void Engine::Manager::Input::Update(const float deltaTime)
{
    GetInstance()->_system->Update(deltaTime);
}

void Engine::Manager::Input::Reset()
{
    GetInstance()->_system->Reset();
}

Engine::Manager::Input::Input()
    : _system(nullptr)
{
}
