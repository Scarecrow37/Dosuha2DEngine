#pragma once

namespace Engine::Manager
{
    class Render : public Base<Render>
    {
        friend const std::shared_ptr<Render>& Manager::Base<Render>::GetInstance();
    public:
        using Renderer = Microsoft::WRL::ComPtr<::Render::IRenderer>;
        static void Initialize(HWND windowHandle, D2D1_SIZE_U size);
        static void Finalize();

        static void BeginDraw();
        static void EndDraw();

        static Microsoft::WRL::ComPtr<::Render::IRenderer> GetRenderer();

    protected:
        Render();

    private:
        Microsoft::WRL::ComPtr<::Render::ISystem> _system;
        Microsoft::WRL::ComPtr<::Render::IRenderer> _renderer;
    };
}
