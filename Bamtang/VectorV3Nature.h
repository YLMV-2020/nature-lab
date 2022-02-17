#pragma once

namespace NatureLab {
    class VectorV3Nature : public INature {
    public:

        inline VectorV3Nature() {
            this->start();
        }

        inline void start() override {

            INature::start();

        }

        inline void update() override {

            INature::update();

        }

        inline void show() override {

            INature::show();
            this->update();

        }



    private:


    };
}