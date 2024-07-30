#pragma once
#include "../Base/Base.hpp"


namespace Engine::Manager
{
    class Window : public Base<Window>
    {
        friend const std::shared_ptr<Window>& Manager::Base<Window>::GetInstance();

    public:
        static void Initialize(HINSTANCE instanceHandle, LPCWSTR gameName, SIZE size, int showCommand);

        static HWND GetWindowHandle();

    protected:
        Window();

    private:
        ::Window::WindowPtr<::Window::ISystem> _system;
        ::Window::WindowPtr<::Window::IHandle> _handle;
        ::Window::WindowPtr<::Window::IClass> _class;
    };
}
