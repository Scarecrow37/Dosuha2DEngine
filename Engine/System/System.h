#pragma once

namespace Engine
{
    class System
    {
    public:
        System(HINSTANCE instanceHandle, int showCommand, LPCWSTR gameName);
        System(const System& other) = delete;
        System(System&& other) noexcept = delete;
        System& operator=(const System& other) = delete;
        System& operator=(System&& other) noexcept = delete;
        virtual ~System() = default;

        void Initialize();
        void Run();
        void Finalize();

    private:
        void Update(float deltaTime);
        void LazyUpdate(float deltaTime);
        void Render(/*TODO Renderer*/);

        
        std::wstring _name;
        bool _isRun;
    };
}
