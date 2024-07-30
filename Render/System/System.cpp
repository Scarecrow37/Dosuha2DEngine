#include "pch.h"
#include "System.h"
#include "../Renderer/Renderer.h"

HRESULT Render::System::QueryInterface(const IID& riid, void** ppvObject)
{
    if (riid == IID_IUnknown) (*ppvObject) = static_cast<IUnknown*>(this);
    else if (riid == IID_ISystem) *ppvObject = static_cast<ISystem*>(this);
    else
    {
        *ppvObject = nullptr;
        return E_NOINTERFACE;
    }
    AddRef();
    return S_OK;
}

ULONG Render::System::AddRef()
{
    return InterlockedIncrement(&_refCount);
}

ULONG Render::System::Release()
{
    const ULONG newRefCount = InterlockedDecrement(&_refCount);
    if (newRefCount == 0) delete this;
    return newRefCount;
}

void Render::System::CreateRenderer(IRenderer** renderer)
{
    *renderer = new Renderer();
}

void Render::System::Initialize(const HWND windowHandle, const D2D1_SIZE_U size)
{
    InitializeCOM();
    InitializeFactory();
    InitializeRenderTarget(windowHandle, size);
}

void Render::System::Finalize()
{
    CoUninitialize();
}

void Render::System::BeginDraw()
{
}

void Render::System::EndDraw()
{
}

Render::System::System()
    : _refCount(1)
{
}

void Render::System::InitializeCOM()
{
    ThrowResultErrorIf<Exception::Error>()(CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED),
                                           L"Failed to initialize COM.");
}

void Render::System::InitializeFactory()
{
    ThrowResultErrorIf<Exception::Error>()(
        D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, _factory.GetAddressOf()),
        L"Failed to create D2D1 factory.");
}

void Render::System::InitializeRenderTarget(const HWND windowHandle, const D2D1_SIZE_U size)
{
    ThrowResultErrorIf<Exception::Error>()(
        _factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
                                         D2D1::HwndRenderTargetProperties(windowHandle, size), &_renderTarget),
        L"Failed to create D2D1 render target.");
}
