#pragma once
#include "Vector3.hpp"

namespace Maths
{

	class Matrix4
	{
	public:

		float mat[4][4];

		Matrix4() = default;

		explicit Matrix4(const float& a_a);
		explicit Matrix4(const float(&a_mat)[4][4]);

		Matrix4 Add(const float& a_a) const;
		Matrix4 Add(const Matrix4& a_m) const;
		Matrix4 Subtract(const float& a_a) const;
		Matrix4 Subtract(const Matrix4& a_m) const;
		Matrix4 Product(const float& a_a) const;
		Matrix4 Product(const Matrix4& a_m) const;

		Vector3 Product(const Vector3& a_m) const;
		Matrix4 Divide(const float& a_a) const;
		Matrix4 Divide(const Matrix4& a_m) const;
		Matrix4 Opposite() const;
		Matrix4 Transpose() const;
		bool IsOrthogonal() const;
		float Trace() const;
		Matrix4 Inverse() const;

		static Matrix4 Translation(const Vector3& a_v);
		static Matrix4 Scale(const Vector3& a_v);
		static Matrix4 RotationX(const float& a_angle);
		static Matrix4 RotationY(const float& a_angle);
		static Matrix4 RotationZ(const float& a_angle);
		static Matrix4 TRS(const Vector3& a_translation, const Vector3& a_rotation, const Vector3& a_scale);

		static Matrix4 zero;
		static Matrix4 identity;

		Matrix4 operator+(const float& a_a) const;
		Matrix4 operator+(const Matrix4& a_m) const;
		Matrix4 operator-(const float& a_a) const;
		Matrix4 operator-(const Matrix4& a_m) const;
		Matrix4 operator*(const float& a_a) const;
		Matrix4 operator*(const Matrix4& a_m) const;

		Vector3 operator*(const Vector3& a_m) const;
		Matrix4 operator/(const float& a_a) const;
		Matrix4 operator/(const Matrix4& a_m) const;
		void operator+=(const float& a_a);
		void operator+=(const Matrix4& a_m);
		void operator*=(const float& a_a);
		void operator*=(const Matrix4& a_m);
		void operator-=(const float& a_a);
		void operator-=(const Matrix4& a_m);
		void operator/=(const float& a_a);
		void operator/=(const Matrix4& a_m);
		bool operator==(const float& a_a) const;
		bool operator==(const Matrix4& a_m) const;
		bool operator!=(const float& a_a) const;
		bool operator!=(const Matrix4& a_m) const;

		void RoundTiny();
		void Print() const;

	};


}


