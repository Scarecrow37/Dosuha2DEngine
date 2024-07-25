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
    // _keyboard.Update();
    if (_mappingContext) _mappingContext->Update(deltaTime);
}

void Input::System::Reset()
{
    // _keyboard.Reset();
}

void Input::System::CreateMappingContext(IMappingContext** mappingContext)
{
    *mappingContext = new MappingContext();
}

