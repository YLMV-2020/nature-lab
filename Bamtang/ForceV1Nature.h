#pragma once

namespace NatureLab {

    struct ForceV1System
    {
        int _width, _height;

        Math::Vector _position;
        Math::Vector _velocity;
        Math::Vector _acceleration;
        float _mass;

        Math::Vector _wind;
        Math::Vector _gravity;

        inline ForceV1System(){
            this->_position = Math::Vector(450, 350);
            this->_velocity = Math::Vector(0.01f, 0.01f);
            this->_acceleration = Math::Vector(0.01f, 0.01f);

            this->_mass = 10.0f;

            this->_wind = Math::Vector(0.01, 0);
            this->_gravity = Math::Vector(0, -0.1);

            this->_width = SceneAssets::SCREEN_WIDTH - SceneAssets::LIMIT_WIDTH;
            this->_height = SceneAssets::SCREEN_HEIGHT - SceneAssets::LIMIT_HEIGHT;
        }

        inline void update(){
            this->applyForce(_wind);
            this->applyForce(_gravity);

            _velocity = _velocity + _acceleration;
            _position = _position + _velocity;
            _acceleration = _acceleration * 0.0f;

            this->checkEdges();
        }

        inline void applyForce(Math::Vector force) {
            _acceleration = _acceleration + (force / _mass);
        }

        inline void checkEdges() {

            if (_position.x > _width) {
                _position.x = _width;
                _velocity.x *= -1;
            }
            else if (_position.x < 0) {
                _velocity.x *= -1;
                _position.x = 0;
            }
            if (_position.y > _height) {
                _velocity.y *= -1;
                _position.y = _height;
            }
            else if (_position.y < 0) {
                _velocity.y *= -1;
                _position.y = 0;
            }
        }

    };

    class ForceV1Nature : public INature {
    public:

        inline ForceV1Nature() {
            this->start();
        }

        inline void start() override {
            INature::start();
            this->_ballTexture = SceneAssets::getTexture("ball");
            this->_natureSystem = new ForceV1System();
        }

        inline void update() override {
            INature::update();
            this->_natureSystem->update();
        }

        inline void show() override {
            INature::show();
            this->update();

            sprite->draw(_ballTexture, Math::Vector(_natureSystem->_position.x, _natureSystem->_position.y), Math::Vector(_natureSystem->_mass * 5, _natureSystem->_mass * 5), 0.0f);
        }

    private:

        ForceV1System* _natureSystem;
        Texture2D _ballTexture;
    };
}