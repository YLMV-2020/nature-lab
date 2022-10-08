#pragma once
namespace glxm {

	constexpr float pi = 3.14159265358979323846f;

	static float radians(const float gradians)
	{
		return gradians * pi / 180.0f;
	}

}