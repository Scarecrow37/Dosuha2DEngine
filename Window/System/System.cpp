#include "pch.h"
#include "System.h"

Window::System::System(const HINSTANCE instanceHandle)
    : _instanceHandle(instanceHandle)
{
}

Window::Class Window::System::Register(const LPCWSTR name) const
{
    return Class(_instanceHandle, name);
}

RECT Window::System::AdjustWindowRect(const SIZE size)
{
    RECT rect = {0, 0, size.cx, size.cy};
    ThrowLastErrorIf<Error>()
        (::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE) == FALSE, L"Adjust window rect fail.");
    return rect;
}

Window::Handle Window::System::Create(const Class& windowClass, const RECT windowRect) const
{
    return Handle(_instanceHandle, windowClass.GetName(), windowRect);
}