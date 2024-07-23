#pragma once

namespace Window
{
    class Handle : public IHandle
    {
    public:
        Handle(HINSTANCE instanceHandle, LPCWSTR className, RECT windowRect);
        Handle(const Handle& other) = delete;
        Handle(Handle&& other) noexcept = delete;
        Handle& operator=(const Handle& other) = delete;
        Handle& operator=(Handle&& other) noexcept = delete;
        ~Handle() override;

        void Show(int showCommand = SW_NORMAL) const override;
        void Update() const override;
        
        void AddReference() override;
        size_t Release() override;

    private:
        HWND _windowHandle;
        size_t _referenceCount;
    };
}
