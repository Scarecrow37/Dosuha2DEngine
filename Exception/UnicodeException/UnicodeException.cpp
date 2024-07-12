#include "pch.h"
#include "UnicodeException.h"

UnicodeException::UnicodeException(std::wstring message)
    : std::exception(ConvertToMultibyte(message).c_str()), _message(std::move(message))
{
}

UnicodeException::UnicodeException(const wchar_t* message)
    : UnicodeException(std::wstring(message))
{
}

std::wstring_view UnicodeException::UnicodeWhat() const noexcept
{
    return _message;
}

std::string UnicodeException::ConvertToMultibyte(const std::wstring& string)
{
    return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(string);
}
