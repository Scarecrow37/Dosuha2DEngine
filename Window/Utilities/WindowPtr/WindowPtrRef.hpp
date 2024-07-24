#pragma once

namespace Window
{
    template <typename T>
    class WindowPtrRef
    {
    public:
        using InterfaceType = typename T::InterfaceType;
        
        explicit WindowPtrRef(T* pointer) noexcept;

        operator InterfaceType**() noexcept;

    private:
        T* _pointer;
    };

    template <typename T>
    WindowPtrRef<T>::WindowPtrRef(T* pointer) noexcept
        : _pointer(pointer)
    {
    }

    template <typename T>
    WindowPtrRef<T>::operator typename T::InterfaceType**() noexcept
    {
        return _pointer->ReleaseAndGetAddressOf();
    }
}
