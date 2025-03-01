#pragma once


namespace Math
{

	static const float m_PI = 3.141592653589793f;

	static float Sqrt(float a_a)
	{
		float t_temp, t_sqrt;
		t_sqrt = a_a / 2.0f;
		t_temp = 0.0f;
		while(t_sqrt != t_temp)
		{
			t_temp = t_sqrt;
			t_sqrt = (a_a / t_temp + t_temp) / 2.0f;
		}
		return t_sqrt;
	}

	static float DegToRad(float a_deg)
	{
		return a_deg * (m_PI / 180.0f);
	}

	static float RadToDeg(float a_rad)
	{
		return a_rad * (180.0f / m_PI);
	}

}
