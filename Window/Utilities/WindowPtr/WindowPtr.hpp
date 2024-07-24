#pragma once

namespace Window
{
    template <typename T> requires std::is_base_of_v<IReferenceCounter, T>
    class WindowPtr
    {
    public:
        using InterfaceType = T;

        WindowPtr();
        explicit WindowPtr(T* pointer);
        WindowPtr(const WindowPtr& other);
        WindowPtr(WindowPtr&& other) noexcept;
        WindowPtr& operator=(const WindowPtr& other);
        WindowPtr& operator=(WindowPtr&& other) noexcept;
        ~WindowPtr();

        T* Get() const noexcept;

        T* operator->() const noexcept;

        WindowPtrRef<WindowPtr> operator&() noexcept;

        T** ReleaseAndGetAddressOf() noexcept;

    private:
        size_t InternalRelease() noexcept;

        T* _pointer;
    };

    template <typename T> requires std::is_base_of_v<IReferenceCounter, T>
    WindowPtr<T>::WindowPtr(const WindowPtr& other)
    {
        _pointer = other._pointer;
        _pointer->AddReference();
    }

    template <typename T> requires std::is_base_of_v<IReferenceCounter, T>
    WindowPtr<T>::WindowPtr(WindowPtr&& other) noexcept
    {
        _pointer = other._pointer;
        other._pointer = nullptr;
    }

    template <typename T> requires std::is_base_of_v<IReferenceCounter, T>
    WindowPtr<T>& WindowPtr<T>::operator=(const WindowPtr& other)
    {
        if (this == &other) return *this;
        _pointer->Release();
        _pointer = other._pointer;
        _pointer->AddReference();
        return *this;
    }

    template <typename T> requires std::is_base_of_v<IReferenceCounter, T>
    WindowPtr<T>& WindowPtr<T>::operator=(WindowPtr&& other) noexcept
    {
        if (this == &other) return *this;
        _pointer->Release();
        _pointer = other._pointer;
        other._pointer = nullptr;
        return *this;
    }

    template <typename T> requires std::is_base_of_v<IReferenceCounter, T>
    WindowPtr<T>::~WindowPtr()
    {
        _pointer->Release();
    }

    template <typename T> requires std::is_base_of_v<IReferenceCounter, T>
    T* WindowPtr<T>::Get() const noexcept
    {
        return _pointer;
    }

    template <typename T> requires std::is_base_of_v<IReferenceCounter, T>
    T* WindowPtr<T>::operator->() const noexcept
    {
        return _pointer;
    }

    template <typename T> requires std::is_base_of_v<IReferenceCounter, T>
    WindowPtrRef<WindowPtr<T>> WindowPtr<T>::operator&() noexcept
    {
        return Window::WindowPtrRef<WindowPtr>(this);
    }

    template <typename T> requires std::is_base_of_v<IReferenceCounter, T>
    T** WindowPtr<T>::ReleaseAndGetAddressOf() noexcept
    {
        InternalRelease();
        return &_pointer;
    }

    template <typename T> requires std::is_base_of_v<IReferenceCounter, T>
    size_t WindowPtr<T>::InternalRelease() noexcept
    {
        size_t reference = 0;
        T* pointer = _pointer;
        if (pointer != nullptr)
        {
            _pointer = nullptr;
            reference = pointer->Release();
        }
        return reference;
    }

    template <typename T> requires std::is_base_of_v<IReferenceCounter, T>
    WindowPtr<T>::WindowPtr()
        : _pointer(nullptr)
    {
    }

    template <typename T> requires std::is_base_of_v<IReferenceCounter, T>
    WindowPtr<T>::WindowPtr(T* pointer)
        : _pointer(pointer)
    {
    }
}
