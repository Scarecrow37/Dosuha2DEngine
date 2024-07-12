#pragma once

namespace Input
{
    union Value
    {
        struct
        {
            short _;
            bool on;
        };

        struct
        {
            float scalar;
        };

        // Vector vector;

        operator bool() const;

        Value& operator+=(const Value& rhs);
    };
}
