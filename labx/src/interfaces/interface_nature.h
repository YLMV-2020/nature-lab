#pragma once

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

        virtual void update()
        {
        }

        virtual void render()
        {
        }

    protected:
        // figure::interface_figure* figure_ = nullptr;
    };
}
