#pragma once
#include <array>

namespace Maths
{
	class Vector3;

	class Matrix3
	{
	public:
		std::array<std::array<float, 3>, 3> mat{};

		explicit Matrix3() = default;
		explicit Matrix3(const float& a_a);
		explicit Matrix3(const std::array<std::array<float, 3>, 3>& a_mat);
		explicit Matrix3(const Vector3& a_v1, const Vector3& a_v2, const Vector3& a_v3);

		[[nodiscard]] inline Matrix3 Add(const float& a_a) const;
		[[nodiscard]] inline Matrix3 Add(const Matrix3& a_m) const;
		[[nodiscard]] inline Matrix3 Subtract(const float& a_a) const;
		[[nodiscard]] inline Matrix3 Subtract(const Matrix3& a_m) const;
		[[nodiscard]] inline Matrix3 Product(const float& a_a) const;
		[[nodiscard]] inline Matrix3 Product(const Matrix3& a_m) const;
		[[nodiscard]] inline Matrix3 Divide(const float& a_a) const;
		[[nodiscard]] inline Matrix3 Divide(const Matrix3& a_m) const;
		[[nodiscard]] inline Matrix3 Opposite() const;
		[[nodiscard]] inline Matrix3 Transpose() const;

		[[nodiscard]] inline float Trace() const;

		inline Matrix3 operator+(const float& a_a) const;
		inline Matrix3 operator+(const Matrix3& a_m) const;
		inline Matrix3 operator-(const float& a_a) const;
		inline Matrix3 operator-(const Matrix3& a_m) const;
		inline Matrix3 operator*(const float& a_a) const;
		inline Matrix3 operator*(const Matrix3& a_m) const;
		inline Matrix3 operator/(const float& a_a) const;
		inline Matrix3 operator/(const Matrix3& a_m) const;

		inline void operator+=(const float& a_a);
		inline void operator+=(const Matrix3& a_m);
		inline void operator*=(const float& a_a);
		inline void operator*=(const Matrix3& a_m);
		inline void operator-=(const float& a_a);
		inline void operator-=(const Matrix3& a_m);
		inline void operator/=(const float& a_a);
		inline void operator/=(const Matrix3& a_m);

		inline bool operator==(const float& a_a) const;
		inline bool operator==(const Matrix3& a_m) const;
		inline bool operator!=(const float& a_a) const;
		inline bool operator!=(const Matrix3& a_m) const;

		inline void Print() const;
	};
}

