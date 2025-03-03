#pragma once

#include "MathsExport.hpp"

namespace Maths
{
	class LUMINOUS_MATHS_API Vector3
	{
	public:
		float x{0.0f}, y{0.0f}, z{0.0f};

		explicit Vector3() = default;
		explicit Vector3(const float& a_a, const float& a_b, const float& a_c);

		[[nodiscard]] inline Vector3 Add(const Vector3& a_v) const;
		[[nodiscard]] inline Vector3 Add(const float& a_a) const;
		[[nodiscard]] inline Vector3 Subtract(const Vector3& a_v) const;
		[[nodiscard]] inline Vector3 Subtract(const float& a_a) const;
		[[nodiscard]] inline Vector3 Product(const Vector3& a_v) const;
		[[nodiscard]] inline Vector3 Product(const float& a_a) const;
		[[nodiscard]] inline Vector3 Invert() const;
		[[nodiscard]] inline Vector3 Normalize() const;
		[[nodiscard]] inline Vector3 CrossProduct(const Vector3& a_v) const;

		[[nodiscard]] inline float Length() const;
		[[nodiscard]] inline float DotProduct(const Vector3& a_v) const;

		void Print() const;

		static Vector3 Zero;
		static Vector3 One;
		static Vector3 XAxis;
		static Vector3 YAxis;
		static Vector3 ZAxis;

		inline Vector3 operator+(const float& a_a) const;
		inline Vector3 operator+(const Vector3& a_v) const;
		inline Vector3 operator-(const float& a_a) const;
		inline Vector3 operator-(const Vector3& a_v) const;
		inline Vector3 operator*(const float& a_a) const;
		inline Vector3 operator*(const Vector3& a_v) const;
		inline Vector3 operator/(const float& a_a) const;
		inline Vector3 operator/(const Vector3& a_v) const;

		inline void operator+=(const float& a_a);
		inline void operator+=(const Vector3& a_v);
		inline void operator*=(const float& a_a);
		inline void operator*=(const Vector3& a_v);
		inline void operator-=(const float& a_a);
		inline void operator-=(const Vector3& a_v);
		inline void operator/=(const float& a_a);
		inline void operator/=(const Vector3& a_v);

		inline bool operator==(const float& a_a) const;
		inline bool operator==(const Vector3& a_v) const;
		inline bool operator!=(const float& a_a) const;
		inline bool operator!=(const Vector3& a_v) const;

		inline float operator[](const int& a_a) const;
	};
}
