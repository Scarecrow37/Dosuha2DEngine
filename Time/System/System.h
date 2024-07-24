#pragma once

namespace Time
{
    class System : public ISystem
    {
    public:
        System();

        void Initialize() noexcept override;
        void Update() noexcept override;
        [[nodiscard]] float GetDeltaTime() const noexcept override;

    private:
        std::chrono::steady_clock::time_point _currentTime;
        std::chrono::steady_clock::time_point _previousTime;
        float _deltaTime;
    };
}
