#pragma once

DEFINE_GUID(IID_IRenderer, 0x3f4b3b1b, 0x7b1b, 0x4b1b, 0x8b, 0x3b, 0x1b, 0x7b, 0x4b, 0x3f, 0x1b, 0x7b);

namespace Render
{
    struct IRenderer : IUnknown
    {
        IRenderer() = default;
        IRenderer(const IRenderer& other) = default;
        IRenderer(IRenderer&& other) noexcept = default;
        IRenderer& operator=(const IRenderer& other) = default;
        IRenderer& operator=(IRenderer&& other) noexcept = default;
        virtual ~IRenderer() = default;
    };
}
