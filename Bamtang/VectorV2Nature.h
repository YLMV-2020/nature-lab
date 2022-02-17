#pragma once

namespace NatureLab {
    class VectorV2Nature : public INature {
    public:

        inline VectorV2Nature() {
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

            Math::Vector start(0, 0);
            Math::Vector end(600, 800);

            Line* line = new Line(start, end);

            line->draw();

            
        }

    private:

        Texture2D _ballTexture;
        int _width, _height;

    public:


    };
}