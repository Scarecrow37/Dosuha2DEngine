#pragma once

namespace Window
{
    struct IClass : IReferenceCounter
    {
        [[nodiscard]] virtual LPCWSTR GetName() const = 0;
    };
}
