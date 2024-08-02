#pragma once
#include "../Object/Object.h"

namespace Engine
{
    class World
    {
    public:
        void Initialize() const;
        void Update(float deltaTime) const;
        void LazyUpdate(float deltaTime) const;
        void Render(Manager::Render::Renderer renderer) const;
        void Finalize() const;

        void AddObject(Object* object);

        template <typename T, typename... Args> requires std::derived_from<T, Object>
        T* CreateObject(Args&&... args)
        {
            T* object = new T(std::forward<Args>(args)...);
            AddObject(object);
            return object;
        }

    private:
        std::list<std::unique_ptr<Object>> _objects;
    };
}
