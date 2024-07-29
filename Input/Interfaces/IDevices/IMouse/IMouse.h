#pragma once

namespace Input::Device
{
    struct IMouse : IDevice
    {
        enum class Button : unsigned char
        {
            Left = 0x01,
            Right = 0x02,
            Middle = 0x04,
            X1 = 0x05,
            X2 = 0x06,
            Max
        };

        enum class Axis : unsigned char
        {
            X,
            Y,
            Wheel,
            Max
        };

        virtual Component::IComponent* GetComponent(Button button) = 0;
        virtual Component::IComponent* GetComponent(Axis axis) = 0;
    };
}
