#pragma once

namespace Input::Exception
{
    class WinAPIError : public ::Exception::UnicodeException
    {
    public:
        WinAPIError() = default;
        WinAPIError(DWORD errorCode, std::wstring message);
        WinAPIError(DWORD errorCode, const wchar_t* message);

        [[nodiscard]] DWORD GetErrorCode() const noexcept;

    private:
        static std::wstring FormatErrorMessage(DWORD errorCode, const std::wstring& message);
        DWORD _errorCode;
    };

    class RuntimeError : public ::Exception::UnicodeException
    {
    public:
        RuntimeError() = default;
        RuntimeError(std::wstring message);
        RuntimeError(const wchar_t* message);
    };
}
