#pragma once

namespace Engine
{
    class System
    {
    public:
        System(const System& other) = delete;
        System(System&& other) noexcept = delete;
        System& operator=(const System& other) = delete;
        System& operator=(System&& other) noexcept = delete;

        void Initialize(HINSTANCE instanceHandle, int showCommand);
        void Run();
        void Finalize();

    protected:
        System() = default;
        ~System() = default;

        std::wstring _gameName;
        SIZE _clientSize;

    private:
        void Update(float deltaTime);
        void LazyUpdate(float deltaTime);
        void Render(/*TODO Renderer*/);

        bool _isRun;
    };
}
