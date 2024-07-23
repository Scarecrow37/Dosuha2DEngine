#pragma once
#include "../Class/Class.h"
#include "../Handle/Handle.h"

namespace Window
{
    class System
    {
    public:
        explicit System(HINSTANCE instanceHandle);

        [[nodiscard]] Class Register(LPCWSTR name) const;
        [[nodiscard]] Handle Create(const Class& windowClass, RECT windowRect) const;
        [[nodiscard]] static RECT AdjustWindowRect(SIZE size);

    private:
        HINSTANCE _instanceHandle;
    };
}
