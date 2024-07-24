#pragma once

namespace Window
{
    struct IClass;
    struct IHandle;

    struct ISystem : IReferenceCounter 
    {
        virtual void Register(LPCWSTR name, IClass** windowClass) const = 0;
        virtual void Create(IClass* windowClass, RECT windowRect, IHandle** handle) const = 0;
    };
}
