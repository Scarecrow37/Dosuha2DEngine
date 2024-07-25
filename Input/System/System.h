#pragma once
#include "../Device/Keyboard/Keyboard.h"

namespace Input
{
    class System : public ISystem
    {
    public:
        System();

        void Update(float deltaTime) override;
        void Reset() override;

        void SetMappingContext(IMappingContext* mappingContext) override;
        void CreateMappingContext(IMappingContext** mappingContext) override;

    private:
        IMappingContext* _mappingContext;
        // Device::Keyboard _keyboard;
    };
}
