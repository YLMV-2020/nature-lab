#pragma once

namespace NatureLab {
	class VectorV1Nature : public INature, ITimeEvent {
	public:

		inline VectorV1Nature() {
			this->start();
		}

		inline void start() override {

			INature::start();

			this->_ballTexture = SceneAssets::getTexture("ball");
			this->_position = Math::Vector2(100, 100);
			this->_velocity = Math::Vector2(_velocityX, _velocityY);

			this->_width = SceneAssets::SCREEN_WIDTH - SceneAssets::LIMIT_WIDTH;
			this->_height = SceneAssets::SCREEN_HEIGHT - SceneAssets::LIMIT_HEIGHT;

		}

		inline void update() override {

			ITimeEvent::update();
			INature::update();

			_position = _position + _velocity * deltaTime;
			//Debug::Vector2(_position);

			if ((_position.x > _width) || (_position.x < 0)) {
				_velocity.x = _velocity.x * -1;
			}
			if ((_position.y > _height) || (_position.y < 0)) {
				_velocity.y = _velocity.y * -1;
			}
		}

		inline void show() override {

			INature::show();
			this->update();

			sprite->draw(_ballTexture, Math::Vector2(_position.x, _position.y), Math::Vector2(50, 50), 0.0f);
		}

	private:

		Texture2D _ballTexture;
		int _width, _height;

	public:

		Math::Vector2 _position;
		Math::Vector2 _velocity;

		float _velocityX = 500;
		float _velocityY = 500;

	};
}