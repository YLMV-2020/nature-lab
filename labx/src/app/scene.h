#pragma once
#include "../controls/vector/vector_u1.h"
#include "../lab/vector/vector_n1.h"

namespace nature_lab
{
    class scene
    {
    public:
        scene()
        {
            this->resource = resource::instance();
            this->nc_ = nature_controller::instance();
            this->wc_ = window_controller::instance();
            this->gc_ = gui_controller::instance();

            this->start();
        }

        ~scene()
        {
            glfwTerminate();
            std::cout << ("~Scene() destroyed!");
        }

        void start() const
        {
            this->nc_->start();
            this->wc_->start();
            this->gc_->start();

            gc_->link_window(wc_->get_window());
            load_gui();
        }

        void load_gui() const
        {
            // vector n1
            nc_->add_nature(new vector_n1());
            gc_->add_control(new vector_u1());
            // vector n2

            gc_->load_gui();
        }

        int run() const
        {
            while (wc_->is_run())
            {
                glClearColor(0, 0, 0, 0);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                wc_->update();
                gc_->update();
                nc_->update();

                nc_->render();
                gc_->render();
                wc_->render();
            }
            return 0;
        }

    private:
        window_controller* wc_ = nullptr;
        nature_controller* nc_ = nullptr;
        gui_controller* gc_ = nullptr;
        resource* resource = nullptr;

        std::vector<interface_controller*> controllers_;
    };
}
