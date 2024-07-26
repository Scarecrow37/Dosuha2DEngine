#include "pch.h"
#include "System.h"
#include "../MappingContext/MappingContext.h"

Input::System::System(): _mappingContext(nullptr)
{
}

void Input::System::SetMappingContext(IMappingContext* mappingContext)
{
    _mappingContext = mappingContext;
}

void Input::System::Update(const float deltaTime)
{
    _keyboard.Update();
    _mouse.Update();
    _controller.Update();
    if (_mappingContext) _mappingContext->Update(deltaTime);
}

void Input::System::Reset()
{
    _keyboard.Reset();
    _mouse.Reset();
    _controller.Reset();
}

// void Input::System::CreateMappingContext(IMappingContext** mappingContext)
// {
//     *mappingContext = new MappingContext();
// }

Input::Device::IKeyboard* Input::System::GetKeyboard()
{
    return &_keyboard;
}

Input::Device::IMouse* Input::System::GetMouse()
{
    return &_mouse;
}

Input::Device::IController* Input::System::GetController()
{
    return &_controller;
}

