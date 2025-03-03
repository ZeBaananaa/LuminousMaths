#pragma once

namespace Maths
{
	class Vector2
	{
	public:
		float x{0.0f}, y{0.0f};

		explicit Vector2() = default;
		explicit Vector2(const float& a_a, const float& a_b);

		Vector2 Add(const Vector2& a_v) const;
		Vector2 Add(const float& a_a) const;
		Vector2 Subtract(const Vector2& a_v) const;
		Vector2 Subtract(const float& a_a) const;
		Vector2 Product(const Vector2& a_v) const;
		Vector2 Product(const float& a_a) const;
		Vector2 Invert() const;
		Vector2 Normalize() const;

		float Length() const;
		float DotProduct(const Vector2& a_v) const;

		inline void Print() const;

		static Vector2 Zero;
		static Vector2 One;
		static Vector2 XAxis;
		static Vector2 YAxis;

		Vector2 operator+(const float& a_a) const;
		Vector2 operator+(const Vector2& a_v) const;
		Vector2 operator-(const float& a_a) const;
		Vector2 operator-(const Vector2& a_v) const;
		Vector2 operator*(const float& a_a) const;
		Vector2 operator*(const Vector2& a_v) const;
		Vector2 operator/(const float& a_a) const;
		Vector2 operator/(const Vector2& a_v) const;

		void operator+=(const float& a_a);
		void operator+=(const Vector2& a_v);
		void operator*=(const float& a_a);
		void operator*=(const Vector2& a_v);
		void operator-=(const float& a_a);
		void operator-=(const Vector2& a_v);
		void operator/=(const float& a_a);
		void operator/=(const Vector2& a_v);

		bool operator==(const float& a_a) const;
		bool operator==(const Vector2& a_v) const;
		bool operator!=(const float& a_a) const;
		bool operator!=(const Vector2& a_v) const;

		float operator[](const int& a_a) const;
	};
}
