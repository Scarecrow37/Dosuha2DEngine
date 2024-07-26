#include <iostream>
#include <memory>
#include "../Input/Input.h"
#include "../Input/Trigger/Down/Down.h"
#include "../Time/Time.h"

std::unique_ptr<Input::ISystem> inputSystem;

std::unique_ptr<Time::ISystem> timeSystem;

class A
{
public:
    A() : _context(inputSystem->CreateMappingContext()), _action(_context->CreateAction(L"Action"))
    {
        // set = key, trigger, modifier * ?
        // action = set * ?, listener
        // id, action * ?
        _action->BindKey<Input::Trigger::Down>(inputSystem->GetKeyboard()->GetComponent(Input::Device::IKeyboard::Key::Enter));
    }

    void Method(const Input::Value& value)
    {
        std::cout << std::boolalpha << value.on << std::endl;
    }

private:
    std::shared_ptr<Input::IMappingContext> _context;
    std::shared_ptr<Input::Action> _action;
};


int main(int argc, char* argv[])
{
    inputSystem = std::unique_ptr<Input::ISystem>(Input::CreateSystem());
    timeSystem = std::unique_ptr<Time::ISystem>(Time::CreateSystem());

    timeSystem->Initialize();

    A a;
    while (true)
    {
        timeSystem->Update();
        inputSystem->Update(timeSystem->GetDeltaTime());
        const Input::Value value = inputSystem->GetKeyboard()->GetComponent(Input::Device::IKeyboard::Key::Alt)->
                                                GetValue();
        std::cout << std::boolalpha << value.on << std::endl;

        inputSystem->Reset();
    }
}

