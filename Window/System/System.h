#pragma once

namespace Window
{
    class System : public ISystem
    {
    public:
        explicit System(HINSTANCE instanceHandle);

        void Register(LPCWSTR name, IClass** windowClass) const override;
        void Create(IClass* windowClass, RECT windowRect, IHandle** handle) const override;

        void AddReference() override;
        size_t Release() override;

    private:
        HINSTANCE _instanceHandle;
        size_t _referenceCount;
    };
}
