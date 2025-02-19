#pragma once


namespace Math
{

	static const float m_PI = 3.141592653589793f;

	static float Sqrt(float p_a)
	{
		float t_temp, t_sqrt;
		t_sqrt = p_a / 2.0f;
		t_temp = 0.0f;
		while(t_sqrt != t_temp)
		{
			t_temp = t_sqrt;
			t_sqrt = (p_a / t_temp + t_temp) / 2.0f;
		}
		return t_sqrt;
	}

}
