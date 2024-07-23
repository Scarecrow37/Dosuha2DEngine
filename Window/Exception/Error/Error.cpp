#include "pch.h"
#include "Error.h"

Window::Error::Error(const DWORD errorCode, std::wstring message)
    : UnicodeException(std::move(message)), _errorCode(errorCode)
{
}

Window::Error::Error(const DWORD errorCode, const wchar_t* message)
    : UnicodeException(message), _errorCode(errorCode)
{
}

DWORD Window::Error::GetErrorCode() const noexcept
{
    return _errorCode;
}

std::wstring Window::Error::FormatErrorMessage(const DWORD errorCode, const std::wstring& message)
{
    static constexpr size_t BufferSize = 1024;
    std::vector<wchar_t> buffer(BufferSize);
    FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM, nullptr, errorCode, NULL, buffer.data(), BufferSize - 1, nullptr);
    return std::wstring(buffer.data()) + L" (" + message + L")";
}
