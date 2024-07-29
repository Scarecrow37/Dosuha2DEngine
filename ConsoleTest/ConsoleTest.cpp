#include <iostream>
#include <memory>
#include "../Input/Input.h"
#include "../Time/Time.h"

std::unique_ptr<Input::ISystem> InputSystem;

std::unique_ptr<Time::ISystem> TimeSystem;

class A
{
public:
    A(const std::shared_ptr<Input::IMappingContext>& context)
        : _context(context), _action(_context->CreateAction(L"Action"))
    {
        auto w = _action->BindKey<Input::Trigger::Down, Input::Modifier::SwizzleAxis>(
            InputSystem->GetKeyboard()->GetComponent(Input::Device::IKeyboard::Key::W));
        auto s = _action->BindKey<Input::Trigger::Down, Input::Modifier::SwizzleAxis, Input::Modifier::Negative>(
            InputSystem->GetKeyboard()->GetComponent(Input::Device::IKeyboard::Key::S));
        auto a = _action->BindKey<Input::Trigger::Down, Input::Modifier::Negative>(
            InputSystem->GetKeyboard()->GetComponent(Input::Device::IKeyboard::Key::A));
        auto d = _action->BindKey<Input::Trigger::Down>(
            InputSystem->GetKeyboard()->GetComponent(Input::Device::IKeyboard::Key::D));

        _action->AddListener(Input::TriggerState::Triggered, std::bind(&A::Triggered, this, std::placeholders::_1));
        _action->AddListener(Input::TriggerState::Started, std::bind(&A::Started, this, std::placeholders::_1));
        _action->AddListener(Input::TriggerState::Ongoing, std::bind(&A::Ongoing, this, std::placeholders::_1));
        _action->AddListener(Input::TriggerState::Completed, std::bind(&A::Completed, this, std::placeholders::_1));
        _action->AddListener(Input::TriggerState::Canceled, std::bind(&A::Canceled, this, std::placeholders::_1));
    }

    void Triggered(const Input::Value& value)
    {
        std::cout << "Triggered : " << "X(" << value.x << ") Y(" << value.y << ")" << std::endl;
    }

    void Started(const Input::Value& value)
    {
        std::cout << "Started : " << "X(" << value.x << ") Y(" << value.y << ")" << std::endl;
    }

    void Ongoing(const Input::Value& value)
    {
        std::cout << "Ongoing : " << "X(" << value.x << ") Y(" << value.y << ")" << std::endl;
    }

    void Completed(const Input::Value& value)
    {
        std::cout << "Completed : " << "X(" << value.x << ") Y(" << value.y << ")" << std::endl;
    }

    void Canceled(const Input::Value& value)
    {
        std::cout << "Canceled : " << "X(" << value.x << ") Y(" << value.y << ")" << std::endl;
    }

private:
    std::shared_ptr<Input::IMappingContext> _context;
    std::shared_ptr<Input::Action> _action;
};


int main(int argc, char* argv[])
{
    InputSystem = std::unique_ptr<Input::ISystem>(Input::CreateSystem());
    TimeSystem = std::unique_ptr<Time::ISystem>(Time::CreateSystem());

    TimeSystem->Initialize();

    const std::shared_ptr<Input::IMappingContext> context =
        std::shared_ptr<Input::IMappingContext>(InputSystem->CreateMappingContext());
    InputSystem->SetMappingContext(context.get());

    A a(context);
    while (true)
    {
        TimeSystem->Update();
        InputSystem->Update(TimeSystem->GetDeltaTime());

        InputSystem->Reset();
    }
}

