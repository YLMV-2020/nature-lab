#pragma once
namespace Math {

	const float PI = 3.14159265358979323846f;

	static float radians(float gradians)
	{
		return gradians * PI / 180.0f;
	}

}