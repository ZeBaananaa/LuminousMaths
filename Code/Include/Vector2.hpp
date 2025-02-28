#pragma once

namespace Maths
{
	class Vector2
	{
	public:
		float x{0.0f}, y{0.0f};

		explicit Vector2() = default;
		explicit Vector2(const float& a_a, const float& a_b);

		[[nodiscard]] inline Vector2 Add(const Vector2& a_v) const;
		[[nodiscard]] inline Vector2 Add(const float& a_a) const;
		[[nodiscard]] inline Vector2 Substract(const Vector2& a_v) const;
		[[nodiscard]] inline Vector2 Substract(const float& a_a) const;
		[[nodiscard]] inline Vector2 Product(const Vector2& a_v) const;
		[[nodiscard]] inline Vector2 Product(const float& a_a) const;
		[[nodiscard]] inline Vector2 Invert() const;
		[[nodiscard]] inline Vector2 Normalize() const;

		[[nodiscard]] inline float Length() const;
		[[nodiscard]] inline float DotProduct(const Vector2& a_v) const;

		inline void Print() const;

		static Vector2 Zero;
		static Vector2 One;
		static Vector2 XAxis;
		static Vector2 YAxis;

		inline Vector2 operator+(const float& a_a) const;
		inline Vector2 operator+(const Vector2& a_v) const;
		inline Vector2 operator-(const float& a_a) const;
		inline Vector2 operator-(const Vector2& a_v) const;
		inline Vector2 operator*(const float& a_a) const;
		inline Vector2 operator*(const Vector2& a_v) const;
		inline Vector2 operator/(const float& a_a) const;
		inline Vector2 operator/(const Vector2& a_v) const;

		inline void operator+=(const float& a_a);
		inline void operator+=(const Vector2& a_v);
		inline void operator*=(const float& a_a);
		inline void operator*=(const Vector2& a_v);
		inline void operator-=(const float& a_a);
		inline void operator-=(const Vector2& a_v);
		inline void operator/=(const float& a_a);
		inline void operator/=(const Vector2& a_v);

		inline bool operator==(const float& a_a) const;
		inline bool operator==(const Vector2& a_v) const;
		inline bool operator!=(const float& a_a) const;
		inline bool operator!=(const Vector2& a_v) const;

		inline float operator[](const int& a_a) const;
	};
}
