#pragma once

namespace Window
{
    class Handle
    {
    public:
        Handle(HINSTANCE instanceHandle, LPCWSTR className, RECT windowRect);
        Handle(const Handle& other) = delete;
        Handle(Handle&& other) noexcept = delete;
        Handle& operator=(const Handle& other) = delete;
        Handle& operator=(Handle&& other) noexcept = delete;
        ~Handle();

        void Show(int showCommand = SW_NORMAL) const;
        void Update() const;

    private:
        HWND _windowHandle;
    };
}
