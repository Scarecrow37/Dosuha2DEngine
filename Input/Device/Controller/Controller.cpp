#include "pch.h"
#include "Controller.h"

Input::Device::Controller::Controller()
    : _controllerIndex(Disconnection), _buttons(static_cast<size_t>(Button::Max)),
      _triggers(static_cast<size_t>(Trigger::Max)), _thumbs(static_cast<size_t>(Thumb::Max))
{
    std::ranges::for_each(_triggers, [](auto& trigger) { trigger.second.SetSensitivity(TriggerSensitive); });
    std::ranges::for_each(_thumbs, [](auto& thumb)
    {
        thumb.second.SetSensitivity(ThumbStickSensitive);
        thumb.second.SetDeadZone(ThumbDefaultDeadZone);
    });
}

void Input::Device::Controller::Update()
{
    if (_controllerIndex == Disconnection && CheckConnection()) return;
    XINPUT_STATE state{};
    if (XInputGetState(_controllerIndex, &state) != ERROR_SUCCESS)
    {
        _controllerIndex = Disconnection;
        return;
    }
    
    _triggers[Trigger::Left].SetValue(state.Gamepad.bLeftTrigger);
    _triggers[Trigger::Right].SetValue(state.Gamepad.bRightTrigger);

    _thumbs[Thumb::LeftX].SetValue(state.Gamepad.sThumbLX);
    _thumbs[Thumb::LeftY].SetValue(state.Gamepad.sThumbLY);
    _thumbs[Thumb::RightX].SetValue(state.Gamepad.sThumbRX);
    _thumbs[Thumb::RightY].SetValue(state.Gamepad.sThumbRY);

    for (unsigned short button = 0; button < static_cast<unsigned short>(Button::Max); ++button)
    {
        _buttons[static_cast<Button>(button)].SetValue(GetFlag(static_cast<Button>(button)) & state.Gamepad.wButtons);
    }
}

void Input::Device::Controller::Reset()
{
    std::ranges::for_each(_buttons, [](auto& button) { button.second.Reset(); });
    std::ranges::for_each(_triggers, [](auto& trigger) { trigger.second.Reset(); });
    std::ranges::for_each(_thumbs, [](auto& thumb) { thumb.second.Reset(); });
}

Input::Component::IComponent* Input::Device::Controller::GetComponent(Button button)
{
    return &_buttons[button];
}

Input::Component::IComponent* Input::Device::Controller::GetComponent(Trigger trigger)
{
    return &_triggers[trigger];
}

Input::Component::IComponent* Input::Device::Controller::GetComponent(Thumb thumb)
{
    return &_thumbs[thumb];
}

bool Input::Device::Controller::CheckConnection()
{
    return false;
}
