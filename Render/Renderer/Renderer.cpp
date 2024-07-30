#include "pch.h"
#include "Renderer.h"

HRESULT Render::Renderer::QueryInterface(const IID& riid, void** ppvObject)
{
    if (riid == IID_IUnknown) (*ppvObject) = static_cast<IUnknown*>(this);
    else if (riid == IID_IRenderer) *ppvObject = static_cast<IRenderer*>(this);
    else
    {
        *ppvObject = nullptr;
        return E_NOINTERFACE;
    }
    AddRef();
    return S_OK;
}

ULONG Render::Renderer::AddRef()
{
    return InterlockedIncrement(&_refCount);
}

ULONG Render::Renderer::Release()
{
    const ULONG newRefCount = InterlockedDecrement(&_refCount);
    if (newRefCount == 0) delete this;
    return newRefCount;
}

Render::Renderer::Renderer()
    : _refCount(1)
{
}
