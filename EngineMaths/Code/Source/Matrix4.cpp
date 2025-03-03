#include "pch.h"
#include "Matrix4.h"
#include <iostream>
#include "Utils.h"


namespace Math
{

	Matrix4 Matrix4::zero = Matrix4(0.0f);
	Matrix4 Matrix4::identity = Matrix4({ {1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1} });

	Matrix4 Matrix4::Translation(Vector3 a_v)
	{
		Matrix4 t_mat = identity;
		t_mat.mat[0][3] = a_v.x;
		t_mat.mat[1][3] = a_v.y;
		t_mat.mat[2][3] = a_v.z;
		return t_mat;
	}

	Matrix4 Matrix4::Scale(Vector3 a_v)
	{
		Matrix4 t_mat = identity;
		t_mat.mat[0][0] = a_v.x;
		t_mat.mat[1][1] = a_v.y;
		t_mat.mat[2][2] = a_v.z;
		return t_mat;
	}

	Matrix4 Matrix4::RotationX(float a_angle)
	{
		float t_radAngle = Math::DegToRad(a_angle);

		Matrix4 t_mat = identity;
		float t_c = cos(t_radAngle);
		float t_s = sin(t_radAngle);
		t_mat.mat[1][1] = t_c;
		t_mat.mat[1][2] = t_s;
		t_mat.mat[2][1] = -t_s;
		t_mat.mat[2][2] = t_c;
		return t_mat;
	}

	Matrix4 Matrix4::RotationY(float a_angle)
	{
		float t_radAngle = Math::DegToRad(a_angle);

		Matrix4 t_mat = identity;
		float t_c = cos(t_radAngle);
		float t_s = sin(t_radAngle);
		t_mat.mat[0][0] = t_c;
		t_mat.mat[0][2] = -t_s;
		t_mat.mat[2][0] = t_s;
		t_mat.mat[2][2] = t_c;
		return t_mat;
	}

	Matrix4 Matrix4::RotationZ(float a_angle)
	{

		float t_radAngle = Math::DegToRad(a_angle);

		Matrix4 t_mat = identity;
		float t_c = cos(t_radAngle);
		float t_s = sin(t_radAngle);
		t_mat.mat[0][0] = t_c;
		t_mat.mat[0][1] = t_s;
		t_mat.mat[1][0] = -t_s;
		t_mat.mat[1][1] = t_c;
		return t_mat;
	}

	Matrix4 Matrix4::TRS(Vector3 a_translation, Vector3 a_rotation, Vector3 a_scale)
	{
		Matrix4 t_mat = Translation(a_translation) *
			RotationZ(a_rotation.z) *
			RotationY(a_rotation.y) *
			RotationX(a_rotation.x) *
			Scale(a_scale);
		t_mat.RoundTiny();
		return t_mat;
	}

	Matrix4::Matrix4(float a_a)
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				mat[i][j] = a_a;
			}
		}
	}

	Matrix4::Matrix4(const float(&a_mat)[4][4])
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				mat[i][j] = a_mat[i][j];
			}
		}
	}

	Matrix4 Math::Matrix4::Add(float a_a)
	{
		Matrix4 t_m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				t_m.mat[i][j] = mat[i][j] + a_a;
			}
		}
		return t_m;
	}

	Matrix4 Math::Matrix4::Add(Matrix4 a_m)
	{
		Matrix4 t_m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				t_m.mat[i][j] = mat[i][j] + a_m.mat[i][j];
			}
		}
		return t_m;
	}

	Matrix4 Math::Matrix4::Substract(float a_a)
	{
		Matrix4 t_m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				t_m.mat[i][j] = mat[i][j] - a_a;
			}
		}
		return t_m;
	}

	Matrix4 Math::Matrix4::Substract(Matrix4 a_m)
	{
		Matrix4 t_m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				t_m.mat[i][j] = mat[i][j] - a_m.mat[i][j];
			}
		}
		return t_m;
	}

	Matrix4 Math::Matrix4::Product(float a_a)
	{
		Matrix4 t_m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				t_m.mat[i][j] = mat[i][j] * a_a;
			}
		}
		return t_m;
	}

	Matrix4 Math::Matrix4::Product(Matrix4 a_m) {
		Matrix4 t_m;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				t_m.mat[i][j] = 0;
				for (int k = 0; k < 4; ++k) {
					t_m.mat[i][j] += mat[i][k] * a_m.mat[k][j];
				}
			}
		}
		return t_m;
	}

	Vector3 Matrix4::Product(Vector3 a_m)
	{
		float t_vec[4] = { a_m.x, a_m.y, a_m.z, 1.0f };
		float t_result[4] = { 0, 0, 0, 0 };

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				t_result[i] += mat[i][j] * t_vec[j];
			}
		}
		return Vector3(t_result[0], t_result[1], t_result[2]);
	}

	Matrix4 Math::Matrix4::Divide(float a_a)
	{
		Matrix4 t_m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				t_m.mat[i][j] = mat[i][j] / a_a;
			}
		}
		return t_m;
	}

	Matrix4 Math::Matrix4::Divide(Matrix4 a_m)
	{
		Matrix4 t_m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				t_m.mat[i][j] = mat[i][j] / a_m.mat[i][j];
			}
		}
		return t_m;
	}

	Matrix4 Matrix4::Opposite()
	{
		Matrix4 t_m = Matrix4(mat);
		return t_m * -1;
	}

	Matrix4 Matrix4::Transpose()
	{
		Matrix4 t_m = Matrix4();
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				t_m.mat[i][j] = mat[j][i];
			}
		}
		return t_m;
	}

	bool Matrix4::IsOrthogonal()
	{
		Matrix4 t_transpose = Transpose();
		return (t_transpose * *this) == identity;
	}

	float Matrix4::Trace()
	{
		return mat[0][0] + mat[1][1] + mat[2][2] + mat[3][3];
	}

	Matrix4 Matrix4::Inverse()
	{
		if (IsOrthogonal())
		{
			return Transpose();
		}else
		{
			std::cout << "Matrix isn't orthogonal." << '\n';
			return *this;
		}
		
	}

	

	Matrix4 Matrix4::operator+(const float a_a)
	{
		return Add(a_a);
	}

	Matrix4 Matrix4::operator+(const Matrix4& a_m)
	{
		return Add(a_m);
	}

	Matrix4 Matrix4::operator-(const float a_a)
	{
		return Substract(a_a);
	}

	Matrix4 Matrix4::operator-(const Matrix4& a_m)
	{
		return Substract(a_m);
	}

	Matrix4 Matrix4::operator*(const float a_a)
	{
		return Product(a_a);
	}

	Matrix4 Matrix4::operator*(const Matrix4& a_m)
	{
		return Product(a_m);
	}

	Vector3 Matrix4::operator*(const Vector3& a_m)
	{
		return Product(a_m);
	}

	Matrix4 Matrix4::operator/(const float a_a)
	{
		return Divide(a_a);
	}

	Matrix4 Matrix4::operator/(const Matrix4& a_m)
	{
		return Divide(a_m);
	}

	void Matrix4::operator+=(const float a_a)
	{
		*this = *this + a_a;
	}

	void Matrix4::operator+=(const Matrix4& a_m)
	{
		*this = *this + a_m;
	}

	void Matrix4::operator*=(const float a_a)
	{
		*this = *this * a_a;
	}

	void Matrix4::operator*=(const Matrix4& a_m)
	{
		*this = *this * a_m;
	}

	void Matrix4::operator-=(const float a_a)
	{
		*this = *this - a_a;
	}

	void Matrix4::operator-=(const Matrix4& a_m)
	{
		*this = *this - a_m;
	}

	void Matrix4::operator/=(const float a_a)
	{
		*this = *this / a_a;
	}

	void Matrix4::operator/=(const Matrix4& a_m)
	{
		*this = *this / a_m;
	}

	bool Matrix4::operator==(const float a_a)
	{
		bool t_condition = true;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (mat[i][j] != a_a)
					t_condition = false;
			}
			if (!t_condition)
				break;
		}
		return t_condition;
	}

	bool Matrix4::operator==(const Matrix4 a_m)
	{
		bool t_condition = true;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (mat[i][j] != a_m.mat[i][j])
					t_condition = false;
			}
			if (!t_condition)
				break;
		}
		return t_condition;
	}

	bool Matrix4::operator!=(const float a_a)
	{
		bool t_condition = true;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (mat[i][j] == a_a)
					t_condition = false;
			}
			if (!t_condition)
				break;
		}
		return t_condition;
	}

	bool Matrix4::operator!=(const Matrix4 a_m)
	{
		bool t_condition = true;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (mat[i][j] == a_m.mat[i][j])
					t_condition = false;
			}
			if (!t_condition)
				break;
		}
		return t_condition;
	}

	void Matrix4::RoundTiny()
	{
		float t_epsilon = 1e-6f;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (fabs(mat[i][j]) < t_epsilon)
				{
					mat[i][j] = 0.0f;
				}
			}
		}
	}


	void Matrix4::Print()
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				std::cout << mat[i][j] << ", ";
			}
			std::cout << '\n';
		}
	}
}


