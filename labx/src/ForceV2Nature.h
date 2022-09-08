#pragma once

namespace NatureLab {

    struct ForceV2System
    {
        glxm::vec2 _position;
        glxm::vec2 _velocity;
        glxm::vec2 _acceleration;
        float _mass;

        inline ForceV2System() {
            this->_position = glxm::vec2(450, 350);
            this->_velocity = glxm::vec2(0.01f, 0.01f);
            this->_acceleration = glxm::vec2(0.01f, 0.01f);
            this->_mass = 10.0f;
        }

        inline ForceV2System(float mass, glxm::vec2 position = glxm::vec2(50, 600)) {
            this->_position = position;
            this->_velocity = glxm::vec2(0.01f, 0.01f);
            this->_acceleration = glxm::vec2(0.01f, 0.01f);
            this->_mass = mass;
        }

        inline void update(const int& _width, const int& _height) {
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

    class ForceV2Nature : public INature {
    public:

        inline ForceV2Nature() {
            this->start();
        }

        inline void start() override {
            INature::start();
            this->_ballTexture = SceneAssets::get_texture("ball");

            this->_wind = glxm::vec2(0.1f, 0);
            this->_gravity = glxm::vec2(0, -9.81f);

            this->_width = SceneAssets::SCREEN_WIDTH - SceneAssets::LIMIT_WIDTH;
            this->_height = SceneAssets::SCREEN_HEIGHT - SceneAssets::LIMIT_HEIGHT;

            this->_frictionMag = _c * _normal;
            this->_friction = glxm::vec2(0.01f, 0.01f);
            

            for (int i = 0; i < _balls; i++)
                _natureSystem.push_back(new ForceV2System(rand() % 30 + 10/*,
                    Math::Vector(1 + rand() % _width, 1 + rand() % _height)*/)
                );
        }

        inline void update() override {
            INature::update();

            for (const auto& it : _natureSystem) {

                this->_friction = it->_velocity;
                this->_friction = this->_friction * -1.0f;
                this->_friction.normalized();
                this->_friction = this->_friction * _frictionMag;
                this->_friction.y *= -1;


                it->applyForce(_friction);
                it->applyForce(_wind);
                //_gravity.y = -it->_mass * 0.1f; // sea el peso de cualquier objeto caerán a la misma velocidad
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

        std::vector<ForceV2System*> _natureSystem;
        Texture2D _ballTexture;

        glxm::vec2 _wind;
        glxm::vec2 _gravity;

        int _width, _height;
        int _balls = 10;

        float _c = 0.01f;
        float _normal = 1.0f;

        float _frictionMag;
        glxm::vec2 _friction;
    };
}