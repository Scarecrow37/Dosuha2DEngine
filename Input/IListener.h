#pragma once

namespace Input
{
    struct IListener
    {
        IListener() = default;
        IListener(const IListener& other) = default;
        IListener(IListener&& other) noexcept = default;
        IListener& operator=(const IListener& other) = default;
        IListener& operator=(IListener&& other) noexcept = default;
        virtual ~IListener() = default;

        virtual void Started(const Value& value) = 0;
        virtual void Ongoing(const Value& value) = 0;
        virtual void Triggered(const Value& value) = 0;
        virtual void Completed(const Value& value) = 0;
        virtual void Canceled(const Value& value) = 0;
    };
}
