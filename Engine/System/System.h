﻿#pragma once

namespace Engine
{
    class World;

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
        System(const std::wstring& gameName, SIZE clientSize);
        ~System() = default;

        std::wstring _gameName;
        SIZE _clientSize;

    private:
        void Update(float deltaTime) const;
        void LazyUpdate(float deltaTime) const;
        void Render(const Manager::Render::Renderer& renderer) const;

        bool _isRun;

        std::unique_ptr<World> _world;
    };
}
