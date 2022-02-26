#pragma once

namespace NatureLab {

    struct ForceV3System
    {
        Math::Vector2 _position;
        Math::Vector2 _velocity;
        Math::Vector2 _acceleration;
        float _mass;

        inline ForceV3System() {
            this->_position = Math::Vector2(450, 350);
            this->_velocity = Math::Vector2(0.01f, 0.01f);
            this->_acceleration = Math::Vector2(0.01f, 0.01f);
            this->_mass = 10.0f;
        }

        inline ForceV3System(float mass, Math::Vector2 position = Math::Vector2(50, 600)) {
            this->_position = position;
            this->_velocity = Math::Vector2(0.01f, 0.01f);
            this->_acceleration = Math::Vector2(0.01f, 0.01f);
            this->_mass = mass;
        }

        inline void update(const int& _width, const int& _height) {
            _velocity = _velocity + _acceleration;
            _position = _position + _velocity;
            _acceleration = _acceleration * 0.0f;

            this->checkEdges(_width, _height);
        }

        inline void applyForce(Math::Vector2 force) {
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

    struct LiquidForceV3 {
        int _x, _y;
        int _width, _height;
        float _c;

        LiquidForceV3(int x, int y, int w, int h, float c){
            this->_x = x;
            this->_y = y;
            this->_width = w;
            this->_height = h;
            this->_c = c;
        }

        bool contains(const ForceV3System &v) {
            return v._position.x > this->_x && v._position.x<this->_x + this->_width
                && v._position.y > this->_y && v._position.y < this->_y + this->_height;
        }

        Math::Vector2 calculateDrag(const ForceV3System& v) {
            // Magnitude is coefficient * speed squared
            auto speed = Math::Vector2::magnitude(v._velocity);
            auto dragMagnitude = this->_c * speed * speed;

            // Direction is inverse of velocity
            auto dragForce = v._velocity;
            dragForce = dragForce * -1;

            // Scale according to magnitude
            dragForce.normalized();
            dragForce = dragForce * dragMagnitude;
            return dragForce;
        }
    };

    class ForceV3Nature : public INature {
    public:

        inline ForceV3Nature() {
            this->start();
        }

        inline void start() override {
            INature::start();

            this->_ballTexture = SceneAssets::getTexture("ball");
            this->_redTexture = SceneAssets::getTexture("blue");
            this->_gravity = Math::Vector2(0, -9.81f);

            this->_width = SceneAssets::SCREEN_WIDTH - SceneAssets::LIMIT_WIDTH;
            this->_height = SceneAssets::SCREEN_HEIGHT - SceneAssets::LIMIT_HEIGHT;

            this->liquid = new LiquidForceV3(0, 0, SceneAssets::SCREEN_WIDTH, (SceneAssets::SCREEN_HEIGHT - SceneAssets::LIMIT_HEIGHT) / 2, 0.1f);

            _natureSystem.clear();

            for (int i = 0; i < _balls; i++)
                _natureSystem.push_back(new ForceV3System((rand() % 25 + 25) / 10.0f ,
                    Math::Vector2(20 + i * _width / _balls, 600))
                );
        }

        inline void update() override {
            INature::update();

            for (const auto& it : _natureSystem) {

                if (liquid->contains(*it)) {
                    // Calculate drag force
                    auto dragForce = liquid->calculateDrag(*it);
                    // Apply drag force to Mover
                    it->applyForce(dragForce);
                }

                _gravity.y = -it->_mass * 0.1f; // Gravity is scaled by mass here!
                it->applyForce(_gravity);
                it->update(this->_width, this->_height);
            }
        }

        inline void show() override {
            INature::show();
            this->update();
            sprite->draw(_redTexture, Math::Vector2(0, 0), Math::Vector2(SceneAssets::SCREEN_WIDTH, (SceneAssets::SCREEN_HEIGHT - SceneAssets::LIMIT_HEIGHT) / 2), 0);
            for (const auto& it : _natureSystem) {
                sprite->draw(_ballTexture, Math::Vector2(it->_position.x, it->_position.y), Math::Vector2(it->_mass * 25.0f, it->_mass * 25.0f), 0);
            }
        }

    private:

        std::vector<ForceV3System*> _natureSystem;
        Texture2D _ballTexture;
        Texture2D _redTexture;

        LiquidForceV3* liquid;
        Math::Vector2 _gravity;

        int _width, _height;
        int _balls = 9;

    };
}