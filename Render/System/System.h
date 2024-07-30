#pragma once

namespace Render
{
    class System : public ISystem
    {
        friend void CreateSystem(ISystem** system);

    public:
        HRESULT QueryInterface(const IID& riid, void** ppvObject) override;
        ULONG AddRef() override;
        ULONG Release() override;

        void CreateRenderer(IRenderer** renderer) override;

        void Initialize(HWND windowHandle, D2D1_SIZE_U size) override;
        void Finalize() override;

        void BeginDraw() override;
        void EndDraw() override;

    private:
        System();
        static void InitializeCOM();
        void InitializeFactory();
        void InitializeRenderTarget(HWND windowHandle, D2D1_SIZE_U size);

        ULONG _refCount;

        Microsoft::WRL::ComPtr<ID2D1Factory8> _factory;
        Microsoft::WRL::ComPtr<ID2D1HwndRenderTarget> _renderTarget;
    };
}
