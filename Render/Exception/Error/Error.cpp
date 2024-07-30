#include "pch.h"
#include "Error.h"

Render::Exception::Error::Error(const HRESULT result, std::wstring message)
    :UnicodeException(std::move(message)), _result(result)
{
}

Render::Exception::Error::Error(const HRESULT result, const wchar_t* message)
    : UnicodeException(message), _result(result)
{
}

HRESULT Render::Exception::Error::GetResult() const noexcept
{
    return _result;
}
