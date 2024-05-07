#include "Debug.h"

namespace NatureLab {

	void Debug::Vector2(const Math::Vector2& v)
	{
		spdlog::info("Vector({},{})", v.x, v.y);
	}
}