#include "pch.h"
#include "Object.h"

Engine::Object::Object()
    :_ownerWorld(nullptr), _rootScene(nullptr)
{
}

void Engine::Object::Initialize()
{
}

void Engine::Object::Update(float deltaTime)
{
}

void Engine::Object::LazyUpdate(float deltaTime)
{
}

void Engine::Object::Render(Manager::Render::Renderer renderer)
{
}

void Engine::Object::Finalize()
{
}

void Engine::Object::SetOwner(World* owner)
{
    _ownerWorld = owner;
}

void Engine::Object::SetRootScene(Scene* rootScene)
{
    _rootScene = rootScene;
}
