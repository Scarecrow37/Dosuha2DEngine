#include "pch.h"
#include "Functions.h"
#include "../../System/System.h"

void Render::CreateSystem(ISystem** system)
{
    *system = new System();
}
