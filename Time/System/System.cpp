#include "pch.h"
#include "System.h"

Time::System::System()
    : _deltaTime(0)
{
}

void Time::System::Initialize() noexcept
{
    _currentTime = std::chrono::steady_clock::now();
}

void Time::System::Update() noexcept
{
    _previousTime = _currentTime;
    _currentTime = std::chrono::steady_clock::now();
    _deltaTime = std::chrono::duration<float>(_currentTime - _previousTime).count();
}

float Time::System::GetDeltaTime() const noexcept
{
    return _deltaTime;
}
