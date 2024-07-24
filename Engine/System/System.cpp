#include "pch.h"
#include "System.h"


void Engine::System::Initialize(const HINSTANCE instanceHandle, const int showCommand)
{
    Manager::Window::Initialize(instanceHandle, _gameName.c_str(), _clientSize, showCommand);
    Manager::Time::Initialize();
    _isRun = true;
}

void Engine::System::Run()
{
    MSG message;
    while (_isRun)
    {
        if (PeekMessage(&message, nullptr, NULL, NULL, PM_REMOVE))
        {
            if (message.message == WM_QUIT)
            {
                _isRun = false;
                break;
            }
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
        else
        {
            Manager::Time::Update();
            Update(Manager::Time::GetDeltaTime());
            LazyUpdate(Manager::Time::GetDeltaTime());
            // Render();
        }
    }
}

void Engine::System::Finalize()
{
}

void Engine::System::Update(float deltaTime)
{
}

void Engine::System::LazyUpdate(float deltaTime)
{
}

void Engine::System::Render()
{
}
