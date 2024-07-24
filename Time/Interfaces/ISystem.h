#pragma once

namespace Time
{
    struct ISystem
    {
        ISystem() = default;
        ISystem(const ISystem& other) = default;
        ISystem(ISystem&& other) noexcept = default;
        ISystem& operator=(const ISystem& other) = default;
        ISystem& operator=(ISystem&& other) noexcept = default;
        virtual ~ISystem() = default;

        virtual void Initialize() noexcept = 0;
        virtual void Update() noexcept = 0;
        [[nodiscard]] virtual float GetDeltaTime() const noexcept = 0;
    };
}
