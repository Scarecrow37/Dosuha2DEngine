#include "pch.h"
#include "System.h"

#include "../../Window/Utility/Functions/Functions.h"
#include "../../Window/Utility/WindowPtr/WindowPtr.hpp"


Engine::System::System(const HINSTANCE instanceHandle, const LPCWSTR gameName)
    : _window(nullptr), _isRun(false)
{
    Window::WindowPtr<Window::ISystem> windowSystem;
    CreateWindowSystem(instanceHandle, &windowSystem);
    Window::WindowPtr<Window::IClass> windowClass;
    windowSystem->Register(gameName, &windowClass);
    windowSystem->Create(windowClass.Get(), Window::AdjustWindowRect({800, 600}), &_window);
}
