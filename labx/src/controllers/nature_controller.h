#pragma once
#include "../interfaces/interface_nature.h"

namespace nature_lab
{
    class nature_controller
    {
    public:
        static nature_controller* instance()
        {
            static nature_controller instance;
            return &instance;
        }

        nature_controller()
        {
            this->start();
        }

        void start()
        {
        }

        void render()
        {
            for (interface_nature*& inteface : nature_lab_)
            {
                inteface->render();
            }
        }

        void render(const int index) const
        {
            nature_lab_.at(index)->render();
        }

        interface_nature*& get_nature(const int index)
        {
            return nature_lab_.at(index);
        }
        
        void add_nature(interface_nature* nature)
        {
            this->nature_lab_.push_back(nature);
        }

    private:
        std::vector<interface_nature*> nature_lab_;
    };
}
