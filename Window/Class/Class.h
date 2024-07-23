#pragma once

namespace Window
{
    class Class : public IClass
    {
    public:
        Class(HINSTANCE instanceHandle, LPCWSTR name);
        [[nodiscard]] LPCWSTR GetName() const override;

        void AddReference() override;
        size_t Release() override;

    private:
        static LRESULT DefaultWindowProcedure(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);
        static void PlaceInCenterOfScreen(HWND windowHandle);

        WNDCLASSEX _windowClass;
        size_t _referenceCount;
    };
}
