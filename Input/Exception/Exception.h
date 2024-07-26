#pragma once

#include "Error/Error.h"

template <typename T> requires std::is_base_of_v<Input::Exception::WinAPIError, T>
struct ThrowLastErrorIf
{
    void operator()(const bool expression, const std::wstring& message) const
    {
        if (expression) throw T(GetLastError(), message);
    }
};

template <typename T> requires std::is_base_of_v<Input::Exception::RuntimeError, T>
struct ThrowRuntimeErrorIf
{
    void operator()(const bool expression, const std::wstring& message) const
    {
        if (expression) throw T(message);
    }
};
