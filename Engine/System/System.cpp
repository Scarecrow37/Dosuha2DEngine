#include "pch.h"
#include "System.h"

#include "../World/World.h"


void Engine::System::Initialize(const HINSTANCE instanceHandle, const int showCommand)
{
    Manager::Time::Initialize();
    Manager::Window::Initialize(instanceHandle, _gameName.c_str(), _clientSize, showCommand);
    Manager::Input::Initialize();
    Manager::Render::Initialize(Manager::Window::GetWindowHandle(), D2D1::SizeU(_clientSize.cx, _clientSize.cy));
    _world->Initialize();
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
            Manager::Input::Update(Manager::Time::GetDeltaTime());
            Update(Manager::Time::GetDeltaTime());
            LazyUpdate(Manager::Time::GetDeltaTime());
            Manager::Render::BeginDraw();
            Render(Manager::Render::GetRenderer());
            Manager::Render::EndDraw();
            Manager::Input::Reset();
        }
    }
}

void Engine::System::Finalize()
{
    _world->Finalize();
    Manager::Render::Finalize();
    _isRun = false;
}

Engine::System::System(const std::wstring& gameName, const SIZE clientSize)
    : _gameName(gameName), _clientSize(clientSize), _isRun(false), _world(std::make_unique<World>())
{
}

void Engine::System::Update(const float deltaTime) const
{
    _world->Update(deltaTime);
}

void Engine::System::LazyUpdate(const float deltaTime) const
{
    _world->LazyUpdate(deltaTime);
}

void Engine::System::Render(const Manager::Render::Renderer& renderer) const
{
    _world->Render(renderer);
}
