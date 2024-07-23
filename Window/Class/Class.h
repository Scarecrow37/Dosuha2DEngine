#pragma once

namespace Window
{
    class Class
    {
    public:
        Class(HINSTANCE instanceHandle, LPCWSTR name);

        [[nodiscard]] LPCWSTR GetName() const;

    private:
        static LRESULT DefaultWindowProcedure(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);
        static void PlaceInCenterOfScreen(HWND windowHandle);


        WNDCLASSEX _windowClass;
    };
}
