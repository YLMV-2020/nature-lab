#pragma once

namespace NatureLab {
    class VectorV3Nature : public INature {
    public:

        inline VectorV3Nature() {
            this->start();
        }

        inline void start() override {
            INature::start();

            this->_blockTexture = SceneAssets::getTexture("red");

            this->_center = Math::Vector(SceneAssets::SCREEN_WIDTH / 2, SceneAssets::SCREEN_HEIGHT / 2);
            this->_mouse = Math::Vector(0, 0);
            this->_color = Math::Vector(1, 1, 1);
            this->_line = new Line();

            _colorxyz[0] = _colorxyz[1] = _colorxyz[2] = 1;
        }

        inline void update() override {
            INature::update();
            this->magnitude = Math::Vector::magnitude(_mouse - _center);
        }

        inline void show() override {
            INature::show();
            this->update();

            sprite->draw(_blockTexture, Math::Vector(10, 10), Math::Vector(magnitude, 50));
            _line->draw(_center, _mouse, _color);
        }

        inline void setMouse(float x, float y) {
            _mouse.x = x;
            _mouse.y = y;
        }

        inline void setColor(float x, float y, float z) {
            _color.x = x;
            _color.y = y;
            _color.z = z;
        }

    private:

        Math::Vector _mouse;
        Math::Vector _center;
        Math::Vector _color;

        Line* _line = NULL;
        Texture2D _blockTexture;
        float magnitude;

    public:
        float _colorxyz[3];
    };
}