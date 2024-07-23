#include "pch.h"
#include "Functions.h"
#include "../../System/System.h"


void Window::CreateWindowSystem(const HINSTANCE instanceHandle, ISystem** system)
{
    *system = new System(instanceHandle);
}

RECT Window::AdjustWindowRect(const SIZE size)
{
    RECT rect = {0, 0, size.cx, size.cy};
    ThrowLastErrorIf<Error>()
        (::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE) == FALSE, L"Adjust window rect fail.");
    return rect;
}
