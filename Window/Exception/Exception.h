#pragma once

#include "Error/Error.h"

template <typename T> requires std::is_base_of_v<Window::Exception::Error, T>
struct ThrowLastErrorIf
{
    void operator()(const bool expression, const std::wstring& message) const
    {
        if (expression) throw T(GetLastError(), message);
    }
};
