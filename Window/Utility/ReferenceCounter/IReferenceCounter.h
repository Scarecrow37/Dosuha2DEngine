#pragma once

namespace Window
{
    struct IReferenceCounter
    {
        IReferenceCounter() = default;
        IReferenceCounter(const IReferenceCounter& other) = delete;
        IReferenceCounter(IReferenceCounter&& other) noexcept = delete;
        IReferenceCounter& operator=(const IReferenceCounter& other) = delete;
        IReferenceCounter& operator=(IReferenceCounter&& other) noexcept = delete;
        virtual ~IReferenceCounter() = default;

        virtual void AddReference() = 0;
        virtual size_t Release() = 0;
    };
}
