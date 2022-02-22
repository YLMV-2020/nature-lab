#pragma once

namespace NatureLab {
    class VectorV4Nature : public INature {
    public:

        inline VectorV4Nature() {
            this->start();
        }

        inline void start() override {
            INature::start();

            this->_ballTexture = SceneAssets::getTexture("ball");

            this->_width = SceneAssets::SCREEN_WIDTH - SceneAssets::LIMIT_WIDTH;
            this->_height = SceneAssets::SCREEN_HEIGHT - SceneAssets::LIMIT_HEIGHT;

            this->_position = Math::Vector(0.01f, 0.01f);
            this->_acceleration = Math::Vector(0.0f, 0.0f);
            this->_velocity = Math::Vector(0.0f, 0.0f);
        }

        inline void update() override {
            INature::update();
            this->_dir = _mouse - _position;
            this->_dir = Math::Vector::normalized(_dir);

            this->_acceleration = _dir;
            this->_velocity = this->_velocity + _acceleration;

            this->limit(_limitVelocity);
            this->_position = this->_position + _velocity;
            this->checkEdges();
        }

        inline void show() override {
            INature::show();
            this->update();
            sprite->draw(_ballTexture, Math::Vector(_position.x, _position.y), Math::Vector(50, 50), 0.0f);
        }

        inline void setMouse(float x, float y) {
            _mouse.x = x;
            _mouse.y = y;
        }

        inline void limit(float limit){
            if (this->_velocity.x > 5) this->_velocity.x = limit;
            if (this->_velocity.y > 5) this->_velocity.y = limit;
            if (this->_velocity.x < -5) this->_velocity.x = -limit;
            if (this->_velocity.y < -5) this->_velocity.y = -limit;
        }

    private:

        inline void checkEdges(){
            if (this->_position.x > _width) {
                this->_position.x = 0;
            }
            else if (this->_position.x < 0) {
                this->_position.x = _width;
            }

            if (this->_position.y > _height) {
                this->_position.y = 0;
            }
            else if (this->_position.y < 0) {
                this->_position.y = _height;
            }
        }

    private:

        Texture2D _ballTexture;
        int _width, _height;

        Math::Vector _position;
        Math::Vector _velocity;
        Math::Vector _acceleration;

        Math::Vector _mouse;
        Math::Vector _dir;

    public:

        float _limitVelocity = 5.0f;

    };
}