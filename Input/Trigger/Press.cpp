#include "pch.h"
#include "Press.h"
#include "../IListener.h"

void Input::Press::Update(float deltaTime)
{
    Value value;
    value.scalar = deltaTime;
    _listener->Started(value);
}
