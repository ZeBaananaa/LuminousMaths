#include "pch.h"
#include "Matrix4.h"


namespace Math
{
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

	float Matrix4::Trace()
	{
		return mat[0][0] + mat[1][1] + mat[2][2] + mat[3][3];
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


