#include "pch.h"
#include "Functions.h"
#include "../../System/System.h"

void Time::CreateSystem(ISystem** system)
{
    *system = new System();
}
