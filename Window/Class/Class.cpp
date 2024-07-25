#include "pch.h"
#include "Class.h"

Window::Class::Class(const HINSTANCE instanceHandle, const LPCWSTR name)
    : _windowClass({
          sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, DefaultWindowProcedure,
          NULL, NULL, instanceHandle, LoadIcon(instanceHandle, IDI_APPLICATION),
          LoadCursor(instanceHandle, IDC_ARROW), static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH)),
          nullptr, name, LoadIcon(instanceHandle, IDI_APPLICATION)
      }), _referenceCount(1)
{
    ThrowLastErrorIf<Exception::Error>()
        (RegisterClassEx(&_windowClass) == FALSE, L"Register window class fail.");
}

LPCWSTR Window::Class::GetName() const
{
    return _windowClass.lpszClassName;
}

void Window::Class::AddReference()
{
    _referenceCount++;
}

size_t Window::Class::Release()
{
    if (--_referenceCount > 0) return _referenceCount;
    delete this;
    return 0;
}

LRESULT Window::Class::DefaultWindowProcedure(const HWND windowHandle, const UINT message, const WPARAM wParam,
                                              const LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        PlaceInCenterOfScreen(windowHandle);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(windowHandle, message, wParam, lParam);
    }
    return 0;
}

void Window::Class::PlaceInCenterOfScreen(const HWND windowHandle)
{
    const int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    const int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    RECT rect;
    GetClientRect(windowHandle, &rect);
    ::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
    const int clientWidth = rect.right - rect.left;
    const int clientHeight = rect.bottom - rect.top;
    SetWindowPos(windowHandle, nullptr, screenWidth / 2 - clientWidth / 2, screenHeight / 2 - clientHeight / 2,
                 clientWidth, clientHeight, NULL);
}
