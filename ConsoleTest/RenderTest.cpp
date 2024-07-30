#include "../Exception/Exception.h"
#include "../Render/Render.h"

int main()
{
    Microsoft::WRL::ComPtr<Render::ISystem> system;
    CreateSystem(&system);
}