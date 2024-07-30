#pragma once

namespace Render
{
    class Renderer : public IRenderer
    {
    public:
        Renderer();

        HRESULT QueryInterface(const IID& riid, void** ppvObject) override;
        ULONG AddRef() override;
        ULONG Release() override;

    private:
        ULONG _refCount;
    };
}
