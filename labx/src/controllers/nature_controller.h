#pragma once
#include "../interfaces/interface_nature.h"

namespace nature_lab
{
    class nature_controller final : public interface_controller
    {
    public:
        static nature_controller* instance()
        {
            static nature_controller instance;
            return &instance;
        }

        void start() override
        {
            interface_controller::start();
        }

        void update(const float& delta_time) override
        {
            interface_controller::update(delta_time);
            for (interface_nature*& inteface : nature_lab_)
            {
                inteface->update(delta_time);
            }
        }

        void render() override
        {
            interface_controller::render();
            for (interface_nature*& inteface : nature_lab_)
            {
                inteface->render();
            }
        }

        // void render(const int index) const
        // {
        //     nature_lab_.at(index)->render();
        // }

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
