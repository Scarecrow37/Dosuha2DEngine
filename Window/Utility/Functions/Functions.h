#pragma once

namespace Window
{
    inline void CreateWindowSystem(HINSTANCE instanceHandle, ISystem** system);
    inline RECT AdjustWindowRect(SIZE size);
}
