#pragma once
#include "Sandbox.h"

#include <memory>

namespace box
{
    class SandImgui : public Sandbox
    {   
    private:
    public:
        SandImgui();
        ~SandImgui();
        void RenderInit() override;
        void OnUpdate() override;
        void OnRender() override;
        void OnImGuiRender() override;
    };
}