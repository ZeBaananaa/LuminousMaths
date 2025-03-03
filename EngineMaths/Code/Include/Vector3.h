#pragma once

namespace Math
{
	class Vector3
	{
	public:
		float x{ 0.0f }, y{ 0.0f }, z{ 0.0f };

		Vector3() = default;
		Vector3(float a_a, float a_b, float a_c);

		Vector3 Add(Vector3 a_v);
		Vector3 Add(float a_a);
		Vector3 Substract(Vector3 a_v);
		Vector3 Substract(float a_a);
		Vector3 Product(Vector3 a_v);
		Vector3 Product(float a_a);
		Vector3 Invert();
		float Length();
		Vector3 Normalize();
		float DotProduct(Vector3 a_v);
		Vector3 CrossProduct(Vector3 a_v);
		void Print();

		static Vector3 zero;
		static Vector3 one;
		static Vector3 xAxis;
		static Vector3 yAxis;
		static Vector3 zAxis;

		Vector3 operator+(const float a_a);
		Vector3 operator+(const Vector3& a_v);
		Vector3 operator-(const float a_a);
		Vector3 operator-(Vector3& a_v);
		Vector3 operator*(const float a_a);
		Vector3 operator*(const Vector3& a_v);
		Vector3 operator/(const float a_a);
		Vector3 operator/(Vector3& a_v);
		void operator+=(const float a_a);
		void operator+=(const Vector3& a_v);
		void operator*=(const float a_a);
		void operator*=(const Vector3& a_v);
		void operator-=(const float a_a);
		void operator-=(const Vector3& a_v);
		void operator/=(const float a_a);
		void operator/=(const Vector3& a_v);
		bool operator==(const float a_a);
		bool operator==(const Vector3 a_v);
		bool operator!=(const float a_a);
		bool operator!=(const Vector3 a_v);
		float operator[](const int a_a);

	};


}
