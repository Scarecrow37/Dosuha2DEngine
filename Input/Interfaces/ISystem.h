#pragma once

namespace Input
{
    struct ISystem
    {
        ISystem() = default;
        ISystem(const ISystem&) = default;
        ISystem& operator=(const ISystem&) = default;
        ISystem(ISystem&&) = default;
        ISystem& operator=(ISystem&&) = default;
        virtual ~ISystem() = default;

        virtual void Update(float deltaTime) = 0;
        virtual void Reset() = 0;
        
        virtual void CreateMappingContext(IMappingContext** mappingContext) = 0;
        virtual void SetMappingContext(IMappingContext* mappingContext) = 0;
    };
}
