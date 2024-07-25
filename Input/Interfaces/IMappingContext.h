#pragma once

namespace Input
{
    struct IMappingContext
    {
        IMappingContext() = default;
        IMappingContext(const IMappingContext&) = default;
        IMappingContext& operator=(const IMappingContext&) = default;
        IMappingContext(IMappingContext&&) = default;
        IMappingContext& operator=(IMappingContext&&) = default;
        virtual ~IMappingContext() = default;

        virtual void Update(float deltaTime) = 0;
    };
}
