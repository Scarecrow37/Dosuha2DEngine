#pragma once

namespace Input
{
    struct IModifier;
    template <typename T>
    concept Modifier = std::derived_from<T, IModifier>;
    class Action_;

    class Action
    {
    public:
        explicit Action(const std::shared_ptr<Action_>& action);

        template <typename Trigger, typename Modifiers>
            requires std::derived_from<Trigger, typename Trigger::ITrigger> && Modifier<Modifiers>
        void BindKey(Component::IComponent* component)
        {
        }

        void AddListener(TriggerState state, Listener listener);

    private:
        std::shared_ptr<Action_> _action;
    };
}
