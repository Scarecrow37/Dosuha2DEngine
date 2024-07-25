#pragma once

namespace Input
{
    class MappingContext : public IMappingContext
    {
    public:
        void Update(float deltaTime) override;

    private:
        std::unordered_set<IAction*> _actions;
    };
}
