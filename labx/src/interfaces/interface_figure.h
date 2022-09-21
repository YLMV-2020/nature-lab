#pragma once

namespace figure
{
    class interface_figure
    {
    protected:
        virtual ~interface_figure() = default;
    public:
        virtual void start()
        {
        }

        virtual void update()
        {
        }

        virtual void render()
        {
        }
    };
}
