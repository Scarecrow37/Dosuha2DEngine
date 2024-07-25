#pragma once
#include "../Trigger/Trigger.h"

namespace Input
{
    enum class TriggerState
    {
        Triggered,
        Started,
        Ongoing,
        Completed,
        Canceled
    };
}
