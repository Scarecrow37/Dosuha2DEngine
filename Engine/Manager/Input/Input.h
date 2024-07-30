#pragma once

namespace Engine::Manager
{
    class Input : public Base<Input>
    {
        friend const std::shared_ptr<Input>& Manager::Base<Input>::GetInstance();
    public:
        static void Initialize();
        static void Update(float deltaTime);
        static void Reset();

    protected:
        Input();

    private:
        std::unique_ptr<::Input::ISystem> _system;
    };
}
