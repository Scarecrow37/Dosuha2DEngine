#pragma once

namespace Input::Trigger
{
    class Base
    {
    public:
        Base() = default;
        Base(const Base& other) = default;
        Base(Base&& other) noexcept = default;
        Base& operator=(const Base& other) = default;
        Base& operator=(Base&& other) noexcept = default;
        virtual ~Base() = default;

        virtual void Update(float deltaTime) = 0;

    protected:
        [[nodiscard]] Value GetModifiedValue() const;

    private:
        std::weak_ptr<Component::IComponent> _inputComponent;
        std::vector<std::shared_ptr<IModifier>> _modifiers;
    };
}
