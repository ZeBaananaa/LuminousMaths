

#pragma once


namespace Math
{
	class Vector2
	{
	public:
		float x{ 0.0f }, y{ 0.0f };

		Vector2() = default;
		Vector2(float a_a, float a_b);

		Vector2 Add(Vector2 a_v);
		Vector2 Add(float a_a);
		Vector2 Substract(Vector2 a_v);
		Vector2 Substract(float a_a);
		Vector2 Product(Vector2 a_v);
		Vector2 Product(float a_a);
		Vector2 Invert();
		float Length();
		Vector2 Normalize();
		float DotProduct(Vector2 a_v);
		void Print();

		static Vector2 zero;
		static Vector2 one;
		static Vector2 xAxis;
		static Vector2 yAxis;

		Vector2 operator+(const float a_a);
		Vector2 operator+(const Vector2& a_v);
		Vector2 operator-(const float a_a);
		Vector2 operator-(Vector2& a_v);
		Vector2 operator*(const float a_a);
		Vector2 operator*(const Vector2& a_v);
		Vector2 operator/(const float a_a);
		Vector2 operator/(Vector2& a_v);
		void operator+=(const float a_a);
		void operator+=(const Vector2& a_v);
		void operator*=(const float a_a);
		void operator*=(const Vector2& a_v);
		void operator-=(const float a_a);
		void operator-=(const Vector2& a_v);
		void operator/=(const float a_a);
		void operator/=(const Vector2& a_v);
		bool operator==(const float a_a);
		bool operator==(const Vector2 a_v);
		bool operator!=(const float a_a);
		bool operator!=(const Vector2 a_v);

	};


}


