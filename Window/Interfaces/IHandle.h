#pragma once

namespace Window
{
    struct IHandle : IReferenceCounter
    {
        virtual void Show(int showCommand = SW_NORMAL) const = 0;
        virtual void Update() const = 0;
        virtual HWND Get() = 0;
    };
}
