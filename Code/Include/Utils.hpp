#pragma once

#include "MathsExport.hpp"

namespace Maths
{
	static constexpr float m_PI = 3.141592653589793f;
	static constexpr float PRECISION { 1e-6f };

	float LUMINOUS_MATHS_API Sqrt(const float& a_a);
	float LUMINOUS_MATHS_API DegToRad(const float& a_deg);
	float LUMINOUS_MATHS_API RadToDeg(const float& a_rad);
}
