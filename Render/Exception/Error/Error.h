#pragma once

namespace Render::Exception
{
    class Error : public ::Exception::UnicodeException
    {
    public:
        Error() = default;
        Error(HRESULT result, std::wstring message);
        Error(HRESULT result, const wchar_t* message);

        [[nodiscard]] HRESULT GetResult() const noexcept;

    private:
        HRESULT _result;
    };
}
