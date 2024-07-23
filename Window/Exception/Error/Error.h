#pragma once

namespace Window
{
    class Error : public ::Exception::UnicodeException
    {
    public:
        Error() = default;
        Error(DWORD errorCode, std::wstring message);
        Error(DWORD errorCode, const wchar_t* message);
        
        [[nodiscard]] DWORD GetErrorCode() const noexcept;

    private:
        static std::wstring FormatErrorMessage(DWORD errorCode, const std::wstring& message);
        DWORD _errorCode;
    };
}
