#pragma once

namespace labx
{
    class IFigure
    {
    protected:
        ~IFigure() = default;
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
