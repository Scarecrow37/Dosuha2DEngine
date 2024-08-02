#include "pch.h"
#include "World.h"

void Engine::World::Initialize() const
{
    std::ranges::for_each(_objects, [](const std::unique_ptr<Object>& object) { object->Initialize(); });
}

void Engine::World::Update(float deltaTime) const
{
    // TODO Collision Check
    std::ranges::for_each(_objects, [deltaTime](const std::unique_ptr<Object>& object) { object->Update(deltaTime); });
}

void Engine::World::LazyUpdate(float deltaTime) const
{
    std::ranges::for_each(_objects, [deltaTime](const std::unique_ptr<Object>& object)
    {
        object->LazyUpdate(deltaTime);
    });
}

void Engine::World::Render(Manager::Render::Renderer renderer) const
{
    // TODO Culling
    std::ranges::for_each(_objects, [renderer](const std::unique_ptr<Object>& object) { object->Render(renderer); });
}

void Engine::World::Finalize() const
{
    std::ranges::for_each(_objects, [](const std::unique_ptr<Object>& object) { object->Finalize(); });
}

void Engine::World::AddObject(Object* object)
{
    object->SetOwner(this);
    _objects.push_back(std::unique_ptr<Object>(object));
}
