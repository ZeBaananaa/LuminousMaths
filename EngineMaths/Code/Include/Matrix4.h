#pragma once


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
		Matrix4 Divide(float a_a);
		Matrix4 Divide(Matrix4 a_m);
		Matrix4 Opposite();
		Matrix4 Transpose();
		float Trace();

		Matrix4 operator+(const float a_a);
		Matrix4 operator+(const Matrix4& a_m);
		Matrix4 operator-(const float a_a);
		Matrix4 operator-(const Matrix4& a_m);
		Matrix4 operator*(const float a_a);
		Matrix4 operator*(const Matrix4& a_m);
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

		void Print();

	};


}


