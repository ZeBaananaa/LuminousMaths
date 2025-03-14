#pragma once

namespace Maths
{
	static constexpr float m_PI = 3.141592653589793f;
	static constexpr float PRECISION { 1e-6f };

	float Sqrt(const float& a_a);
	float DegToRad(const float& a_deg);
	float RadToDeg(const float& a_rad);
	float Precise(const float& a_f);
}
