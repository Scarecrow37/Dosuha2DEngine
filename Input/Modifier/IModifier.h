#pragma once

namespace Input
{
    struct IModifier
    {
        IModifier() = default;
        IModifier(const IModifier& other) = default;
        IModifier(IModifier&& other) noexcept = default;
        IModifier& operator=(const IModifier& other) = default;
        IModifier& operator=(IModifier&& other) noexcept = default;
        virtual ~IModifier() = default;

        virtual Value operator()(bool binaryValue) const = 0;
        virtual Value operator()(float scalarValue) const = 0;
        virtual Value operator()(const Value& value) const = 0;
    };
}
