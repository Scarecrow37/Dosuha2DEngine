#pragma once

#include "Error/Error.h"

template <typename T> requires std::is_base_of_v<Render::Exception::Error, T>
struct ThrowResultErrorIf
{
    void operator()(const HRESULT result, const std::wstring& message) const
    {
        if (result != S_OK) throw T(result, message);
    }
};
