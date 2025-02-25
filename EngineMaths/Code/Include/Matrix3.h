#pragma once
#include "Vectors.h"

namespace Math
{
	class Matrix3
	{
	public:

		float mat[3][3];

		Matrix3() = default;
		Matrix3(float a_a);
		Matrix3(const float (& a_mat)[3][3]);
		Matrix3(Vector3 a_v1, Vector3 a_v2, Vector3 a_v3);

		Matrix3 Add(float a_a);
		Matrix3 Add(Matrix3 a_m);
		Matrix3 Substract(float a_a);
		Matrix3 Substract(Matrix3 a_m);
		Matrix3 Product(float a_a);
		Matrix3 Product(Matrix3 a_m);
		Matrix3 Divide(float a_a);
		Matrix3 Divide(Matrix3 a_m);
		Matrix3 Opposite();
		Matrix3 Transpose();
		float Trace();

		Matrix3 operator+(const float a_a);
		Matrix3 operator+(const Matrix3& a_m);
		Matrix3 operator-(const float a_a);
		Matrix3 operator-(const Matrix3& a_m);
		Matrix3 operator*(const float a_a);
		Matrix3 operator*(const Matrix3& a_m);
		Matrix3 operator/(const float a_a);
		Matrix3 operator/(const Matrix3& a_m);
		void operator+=(const float a_a);
		void operator+=(const Matrix3& a_m);
		void operator*=(const float a_a);
		void operator*=(const Matrix3& a_m);
		void operator-=(const float a_a);
		void operator-=(const Matrix3& a_m);
		void operator/=(const float a_a);
		void operator/=(const Matrix3& a_m);
		bool operator==(const float a_a);
		bool operator==(const Matrix3 a_m);
		bool operator!=(const float a_a);
		bool operator!=(const Matrix3 a_m);

		void Print();

	};

}

