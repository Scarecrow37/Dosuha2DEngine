#include "pch.h"
#include "Render.h"

void Engine::Manager::Render::Initialize(const HWND windowHandle, const D2D1_SIZE_U size)
{
    CreateSystem(&GetInstance()->_system);
    GetInstance()->_system->Initialize(windowHandle, size);
    GetInstance()->_system->CreateRenderer(&GetInstance()->_renderer);
}

void Engine::Manager::Render::Finalize()
{
    GetInstance()->_system->Finalize();
}

void Engine::Manager::Render::BeginDraw()
{
    GetInstance()->_system->BeginDraw();
}

void Engine::Manager::Render::EndDraw()
{
    GetInstance()->_system->EndDraw();
}

Microsoft::WRL::ComPtr<::Render::IRenderer> Engine::Manager::Render::GetRenderer()
{
    return GetInstance()->_renderer;
}

Engine::Manager::Render::Render()
    : _system(nullptr)
{
}
