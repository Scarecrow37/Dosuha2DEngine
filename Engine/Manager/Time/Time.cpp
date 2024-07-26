#include "pch.h"
#include "Time.h"

void Engine::Manager::Time::Initialize() noexcept
{
    GetInstance()->_system = std::unique_ptr<::Time::ISystem>(::Time::CreateSystem());
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