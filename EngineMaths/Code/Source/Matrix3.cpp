#include "pch.h"
#include "Matrix3.h"


namespace Math
{
	Matrix3::Matrix3(float a_a)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				mat[i][j] = a_a;
			}
		}
	}

	Matrix3::Matrix3(const float(&a_mat)[3][3])
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				mat[i][j] = a_mat[i][j];
			}
		}
	}

	Matrix3::Matrix3(Vector3 a_v1, Vector3 a_v2, Vector3 a_v3)
	{
		Vector3 t_v[3] = { a_v1,a_v2,a_v3 };
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				mat[i][j] = t_v[i][j];
			}
		}
	}

	Matrix3 Math::Matrix3::Add(float a_a)
	{
		Matrix3 t_m;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][j] + a_a;
			}
		}
		return t_m;
	}

	Matrix3 Math::Matrix3::Add(Matrix3 a_m)
	{
		Matrix3 t_m;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][j] + a_m.mat[i][j];
			}
		}
		return t_m;
	}

	Matrix3 Math::Matrix3::Substract(float a_a)
	{
		Matrix3 t_m;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][j] - a_a;
			}
		}
		return t_m;
	}

	Matrix3 Math::Matrix3::Substract(Matrix3 a_m)
	{
		Matrix3 t_m;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][j] - a_m.mat[i][j];
			}
		}
		return t_m;
	}

	Matrix3 Math::Matrix3::Product(float a_a)
	{
		Matrix3 t_m;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][j] * a_a;
			}
		}
		return t_m;
	}

	Matrix3 Math::Matrix3::Product(Matrix3 a_m)
	{
		Matrix3 t_m;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][0] * a_m.mat[0][j] + a_m.mat[i][1] *  a_m.mat[1][j] + a_m.mat[i][2] * a_m.mat[2][j];
			}
		}
		return t_m;
	}

	Matrix3 Math::Matrix3::Divide(float a_a)
	{
		Matrix3 t_m;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][j] / a_a;
			}
		}
		return t_m;
	}

	Matrix3 Math::Matrix3::Divide(Matrix3 a_m)
	{
		Matrix3 t_m;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][j] / a_m.mat[i][j];
			}
		}
		return t_m;
	}

	Matrix3 Matrix3::Opposite()
	{
		Matrix3 t_m = Matrix3(mat);
		return t_m * -1;
	}

	Matrix3 Matrix3::Transpose()
	{
		Matrix3 t_m = Matrix3();
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[j][i];
			}
		}
		return t_m;
	}

	float Matrix3::Trace()
	{
		return mat[0][0] + mat[1][1] + mat[2][2];
	}

	Matrix3 Matrix3::operator+(const float a_a)
	{
		return Add(a_a);
	}

	Matrix3 Matrix3::operator+(const Matrix3& a_m)
	{
		return Add(a_m);
	}

	Matrix3 Matrix3::operator-(const float a_a)
	{
		return Substract(a_a);
	}

	Matrix3 Matrix3::operator-(const Matrix3& a_m)
	{
		return Substract(a_m);
	}

	Matrix3 Matrix3::operator*(const float a_a)
	{
		return Product(a_a);
	}

	Matrix3 Matrix3::operator*(const Matrix3& a_m)
	{
		return Product(a_m);
	}

	Matrix3 Matrix3::operator/(const float a_a)
	{
		return Divide(a_a);
	}

	Matrix3 Matrix3::operator/(const Matrix3& a_m)
	{
		return Divide(a_m);
	}

	void Matrix3::operator+=(const float a_a)
	{
		*this = *this + a_a;
	}

	void Matrix3::operator+=(const Matrix3& a_m)
	{
		*this = *this + a_m;
	}

	void Matrix3::operator*=(const float a_a)
	{
		*this = *this * a_a;
	}

	void Matrix3::operator*=(const Matrix3& a_m)
	{
		*this = *this * a_m;
	}

	void Matrix3::operator-=(const float a_a)
	{
		*this = *this - a_a;
	}

	void Matrix3::operator-=(const Matrix3& a_m)
	{
		*this = *this - a_m;
	}

	void Matrix3::operator/=(const float a_a)
	{
		*this = *this / a_a;
	}

	void Matrix3::operator/=(const Matrix3& a_m)
	{
		*this = *this / a_m;
	}

	bool Matrix3::operator==(const float a_a)
	{
		bool t_condition = true;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (mat[i][j] != a_a)
					t_condition = false;
			}
			if (!t_condition)
				break;
		}
		return t_condition;
	}

	bool Matrix3::operator==(const Matrix3 a_m)
	{
		bool t_condition = true;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (mat[i][j] != a_m.mat[i][j])
					t_condition = false;
			}
			if (!t_condition)
				break;
		}
		return t_condition;
	}

	bool Matrix3::operator!=(const float a_a)
	{
		bool t_condition = true;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (mat[i][j] == a_a)
					t_condition = false;
			}
			if (!t_condition)
				break;
		}
		return t_condition;
	}

	bool Matrix3::operator!=(const Matrix3 a_m)
	{
		bool t_condition = true;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (mat[i][j] == a_m.mat[i][j])
					t_condition = false;
			}
			if (!t_condition)
				break;
		}
		return t_condition;
	}


	void Matrix3::Print()
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				std::cout << mat[i][j] << ", ";
			}
			std::cout << '\n';
		}
	}

}


