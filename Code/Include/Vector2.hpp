#pragma once

#include "MathsExport.hpp"

namespace Maths
{
	class LUMINOUS_MATHS_API Vector2
	{
	public:
		float x{0.0f}, y{0.0f};

		explicit Vector2() = default;
		explicit Vector2(const float& a_a, const float& a_b);
		explicit Vector2(const float& a_a);

		[[nodiscard]] Vector2 Add(const Vector2& a_v) const;
		[[nodiscard]] Vector2 Add(const float& a_a) const;
		[[nodiscard]] Vector2 Subtract(const Vector2& a_v) const;
		[[nodiscard]] Vector2 Subtract(const float& a_a) const;
		[[nodiscard]] Vector2 Product(const Vector2& a_v) const;
		[[nodiscard]] Vector2 Product(const float& a_a) const;
		[[nodiscard]] Vector2 Invert() const;
		[[nodiscard]] Vector2 Normalize() const;
		[[nodiscard]] float Length() const;
		[[nodiscard]] float DotProduct(const Vector2& a_v) const;

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
