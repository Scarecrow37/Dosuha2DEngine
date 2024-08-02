#pragma once

namespace Engine
{
    class World;
    class Scene;

    class Object
    {
    public:
        Object();

        void Initialize();
        void Update(float deltaTime);
        void LazyUpdate(float deltaTime);
        void Render(Manager::Render::Renderer renderer);
        void Finalize();

        void SetOwner(World* owner);
        void SetRootScene(Scene* rootScene);

    private:
        World* _ownerWorld;
        Scene* _rootScene;
    };
}
