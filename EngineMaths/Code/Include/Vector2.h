

#pragma once


namespace Math
{
	class Vector2
	{
	public:
		float x{ 0.0f }, y{ 0.0f };

		Vector2() = default;
		Vector2(float p_a, float p_b);

		Vector2 Add(Vector2 p_v);
		Vector2 Add(float p_a);
		Vector2 Substract(Vector2 p_v);
		Vector2 Substract(float p_a);
		Vector2 Product(Vector2 p_v);
		Vector2 Product(float p_a);
		float Length();
		Vector2 Normalize();
		float DotProduct(Vector2 p_v);
		float CrossProduct(Vector2 p_v);
		void Print();

		static Vector2 zero;
		static Vector2 one;
		static Vector2 xAxis;
		static Vector2 yAxis;

		Vector2 operator+(const float p_a);
		Vector2 operator+(const Vector2& p_v);
		Vector2 operator-(const float p_a);
		Vector2 operator-(Vector2& p_v);
		Vector2 operator*(const float p_a);
		Vector2 operator*(const Vector2& p_v);
		Vector2 operator/(const float p_a);
		Vector2 operator/(Vector2& p_v);
		void operator+=(const float p_a);
		void operator+=(const Vector2& p_v);
		void operator*=(const float p_a);
		void operator*=(const Vector2& p_v);
		void operator-=(const float p_a);
		void operator-=(const Vector2& p_v);
		void operator/=(const float p_a);
		void operator/=(const Vector2& p_v);

	};


}


