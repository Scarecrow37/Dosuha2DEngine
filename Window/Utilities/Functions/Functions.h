#pragma once

namespace Window
{
    inline void CreateSystem(HINSTANCE instanceHandle, ISystem** system);
    inline RECT AdjustWindowRect(SIZE size);
}
