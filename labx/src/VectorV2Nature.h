#pragma once

namespace NatureLab {
	class VectorV2Nature : public INature {
	public:

		inline VectorV2Nature() {
			this->start();
		}

		inline void start() override {

			INature::start();
			//this->_center = Math::Vector(0, 0);
			this->_center = glxm::vec2(SceneAssets::SCREEN_WIDTH / 2, SceneAssets::SCREEN_HEIGHT / 2);
			this->_mouse = glxm::vec2(0, 0);
			this->_color = glxm::vec4(1, 1, 1);
			this->_line = new Line();

			_colorxyz[0] = _colorxyz[1] = _colorxyz[2] = 1;
		}

		inline void update() override {

			INature::update();
			//_mouse = _mouse - _center;
		}

		inline void show() override {

			INature::show();
			this->update();

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

		glxm::vec2 _mouse;
		glxm::vec2 _center;
		glxm::vec4 _color;

		Line* _line = NULL;

	public:
		float _colorxyz[3];
	};
}