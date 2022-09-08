#pragma once

namespace NatureLab {

    struct ForceV1System
    { 
       glxm::vec2 _position;
        glxm::vec2 _velocity;
        glxm::vec2 _acceleration;
        float _mass;

        inline ForceV1System(){
            this->_position = glxm::vec2(450, 350);
            this->_velocity = glxm::vec2(0.0, 0.0);
            this->_acceleration = glxm::vec2(0.0, 0.0);
            this->_mass = 10.0f;
        }

        inline ForceV1System(float mass, glxm::vec2 position = glxm::vec2(50, 600)) {
            this->_position = position;
            this->_velocity = glxm::vec2(0.0, 0.0);
            this->_acceleration = glxm::vec2(0.0, 0.0);
            this->_mass = mass;
        }

        inline void update(const int& _width, const int& _height){
            _velocity = _velocity + _acceleration;
            _position = _position + _velocity;
            _acceleration = _acceleration * 0.0f;

            this->checkEdges(_width, _height);
        }

        inline void applyForce(glxm::vec2 force) {
            _acceleration = _acceleration + (force / _mass);
        }

        inline void checkEdges(const int& _width, const int& _height) {

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
            this->_ballTexture = SceneAssets::get_texture("ball");

            this->_wind = glxm::vec2(1.1, 0);
            this->_gravity = glxm::vec2(0, -9.81);

            this->_width = SceneAssets::SCREEN_WIDTH - SceneAssets::LIMIT_WIDTH;
            this->_height = SceneAssets::SCREEN_HEIGHT - SceneAssets::LIMIT_HEIGHT;

            for (int i = 0; i < _balls; i++)
                _natureSystem.push_back(new ForceV1System(rand() % 30 + 10/*, 
                    Math::Vector(1 + rand() % _width, 1 + rand() % _height)*/)
                );
        }

        inline void update() override {
            INature::update();

            for (const auto& it : _natureSystem) {
                it->applyForce(_wind);
                it->applyForce(_gravity);
                it->update(this->_width, this->_height);
            }
        }

        inline void show() override {
            INature::show();
            this->update();
            for (const auto& it : _natureSystem) {
                sprite->draw(_ballTexture, glxm::vec2(it->_position.x, it->_position.y), glxm::vec2(it->_mass * 5.0f, it->_mass * 5.0f), -(float)glfwGetTime() * 50);
            }
        }

    private:

        std::vector<ForceV1System*> _natureSystem;
        Texture2D _ballTexture;

        glxm::vec2 _wind;
        glxm::vec2 _gravity;

        int _width, _height;
        int _balls = 10;
    };
}