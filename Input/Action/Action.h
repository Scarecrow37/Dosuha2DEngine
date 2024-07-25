#pragma once

namespace Input
{
    class Action : public IAction
    {
    public:
        void Update(float deltaTime) override;
        void AddListener(TriggerState state, Listener listener) override;
        // template <typename T> requires std::derived_from<T, Trigger::ITrigger>
        // void AddTrigger()

    private:
        std::vector<Trigger::ITrigger*> _triggers;
        std::unordered_map<TriggerState, Trigger::State> _states;
    };
}
