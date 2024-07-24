#include "pch.h"
#include "Window.h"

void Engine::Manager::Window::Initialize(const HINSTANCE instanceHandle, const LPCWSTR gameName, const SIZE size, const int showCommand)
{
    ::Window::CreateSystem(instanceHandle, &GetInstance()->_system);
    GetInstance()->_system->Register(gameName, &GetInstance()->_class);
    GetInstance()->_system->Create(GetInstance()->_class.Get(), ::Window::AdjustWindowRect(size), &GetInstance()->_handle);
    GetInstance()->_handle->Show(showCommand);
    GetInstance()->_handle->Update();
}

Engine::Manager::Window::Window()
    : _system(nullptr), _handle(nullptr), _class(nullptr)
{
}
