#include "pch.h"
#include "Time.h"

void Engine::Manager::Time::Initialize() noexcept
{
    ::Time::ISystem* system;
    CreateSystem(&system);
    GetInstance()->_system = std::unique_ptr<::Time::ISystem>(system);
}

void Engine::Manager::Time::Update() noexcept
{
    GetInstance()->_system->Update();
}

float Engine::Manager::Time::GetDeltaTime() noexcept
{
    return GetInstance()->_system->GetDeltaTime();
}

Engine::Manager::Time::Time()
    : _system(nullptr)
{
}