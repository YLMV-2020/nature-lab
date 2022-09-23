#pragma once
namespace nature_lab
{
    class interface_controller
    {
    public:
        virtual ~interface_controller() = default;
        interface_controller() = default;

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
