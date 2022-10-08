#pragma once
#include "interface_shape.h"

namespace nature_lab
{
    class interface_nature
    {
    public:
        virtual ~interface_nature() = default;

        interface_nature()
        {
        }

        virtual void start()
        {
        }

        virtual void update(const float& delta_time)
        {
        }

        virtual void render()
        {
        }

    protected:
        shape::interface_shape* shape = nullptr;
    };
}
