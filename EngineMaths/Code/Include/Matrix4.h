#pragma once
#include "Vectors.h"

namespace Math
{

	class Matrix4
	{
	public:

		float mat[4][4];

		Matrix4() = default;
		Matrix4(float a_a);
		Matrix4(const float(&a_mat)[4][4]);

		Matrix4 Add(float a_a);
		Matrix4 Add(Matrix4 a_m);
		Matrix4 Substract(float a_a);
		Matrix4 Substract(Matrix4 a_m);
		Matrix4 Product(float a_a);
		Matrix4 Product(Matrix4 a_m);
		Vector3 Product(Vector3 a_m);
		Matrix4 Divide(float a_a);
		Matrix4 Divide(Matrix4 a_m);
		Matrix4 Opposite();
		Matrix4 Transpose();
		bool IsOrthogonal();
		float Trace();
		Matrix4 Inverse();

		static Matrix4 Translation(Vector3 a_v);
		static Matrix4 Scale(Vector3 a_v);
		static Matrix4 RotationX(float a_angle);
		static Matrix4 RotationY(float a_angle);
		static Matrix4 RotationZ(float a_angle);
		static Matrix4 TRS(Vector3 a_translation, Vector3 a_rotation, Vector3 a_scale);

		static Matrix4 zero;
		static Matrix4 identity;

		Matrix4 operator+(const float a_a);
		Matrix4 operator+(const Matrix4& a_m);
		Matrix4 operator-(const float a_a);
		Matrix4 operator-(const Matrix4& a_m);
		Matrix4 operator*(const float a_a);
		Matrix4 operator*(const Matrix4& a_m);
		Vector3 operator*(const Vector3& a_m);
		Matrix4 operator/(const float a_a);
		Matrix4 operator/(const Matrix4& a_m);
		void operator+=(const float a_a);
		void operator+=(const Matrix4& a_m);
		void operator*=(const float a_a);
		void operator*=(const Matrix4& a_m);
		void operator-=(const float a_a);
		void operator-=(const Matrix4& a_m);
		void operator/=(const float a_a);
		void operator/=(const Matrix4& a_m);
		bool operator==(const float a_a);
		bool operator==(const Matrix4 a_m);
		bool operator!=(const float a_a);
		bool operator!=(const Matrix4 a_m);

		void RoundTiny();
		void Print();

	};


}


