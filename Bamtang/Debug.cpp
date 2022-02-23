#include "Debug.h"

namespace NatureLab {

	void Debug::Vector(const Math::Vector& v)
	{
		spdlog::info("Vector({},{},{},{})", v.x, v.y, v.z, v.w);
	}
}