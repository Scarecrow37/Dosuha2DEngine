#include "pch.h"
#include "Handle.h"


Window::Handle::Handle(const HINSTANCE instanceHandle, const LPCWSTR className, const RECT windowRect)
{
    _windowHandle = CreateWindow(className, className, WS_OVERLAPPEDWINDOW,
                                 windowRect.left, windowRect.top, windowRect.right - windowRect.left,
                                 windowRect.bottom - windowRect.top, nullptr, nullptr,
                                 instanceHandle, nullptr);
    ThrowLastErrorIf<Error>()
        (_windowHandle == nullptr, L"Create window fail.");
}

Window::Handle::~Handle()
{
    if (_windowHandle != nullptr) DestroyWindow(_windowHandle);
    _windowHandle = nullptr;
}

void Window::Handle::Show(const int showCommand) const
{
    ThrowLastErrorIf<Error>()
        (_windowHandle == nullptr, L"Show window fail. Window handle is null.");
    ShowWindow(_windowHandle, showCommand);
}

void Window::Handle::Update() const
{
    auto thrower = ThrowLastErrorIf<Error>();
    thrower(_windowHandle == nullptr, L"Update window fail. Window handle is null.");
    thrower(UpdateWindow(_windowHandle) == FALSE, L"Update window fail.");
}
