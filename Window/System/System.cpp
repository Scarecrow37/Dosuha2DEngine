#include "pch.h"
#include "System.h"
#include "../Class/Class.h"
#include "../Handle/Handle.h"

Window::System::System(const HINSTANCE instanceHandle)
    : _instanceHandle(instanceHandle), _referenceCount(1)
{
}

void Window::System::Register(const LPCWSTR name, IClass** windowClass) const
{
    *windowClass = new Class(_instanceHandle, name);
}

void Window::System::Create(IClass* windowClass, const RECT windowRect, IHandle** handle) const
{
    *handle = new Handle(_instanceHandle, windowClass->GetName(), windowRect);
}

void Window::System::AddReference()
{
    _referenceCount++;
}

size_t Window::System::Release()
{
    if (--_referenceCount > 0) return _referenceCount;
    delete this;
    return 0;
}
