#include "Matrix3.hpp"

#include "Vector3.hpp"

#include <iostream>

#include "Utils.hpp"

namespace Maths
{
	Matrix3::Matrix3(const float& a_a)
	{
		mat = {
			a_a, 0.f, 0.f,
			0.f, a_a, 0.f,
			0.f, 0.f, a_a
		};
	}

	Matrix3::Matrix3(const std::array<std::array<float, 3>, 3>& a_mat)
	{
		mat = a_mat;
	}

	Matrix3::Matrix3(const Vector3& a_v1, const Vector3& a_v2, const Vector3& a_v3)
	{
		mat = {
			a_v1.x, a_v1.y, a_v1.z,
			a_v2.x, a_v2.y, a_v2.z,
			a_v3.x, a_v3.y, a_v3.z
		};
	}

	Matrix3 Matrix3::Add(const float& a_a) const
	{
		Matrix3 t_m{};
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][j] + a_a;
			}
		}
		return t_m;
	}

	Matrix3 Matrix3::Add(const Matrix3& a_m) const
	{
		Matrix3 t_m{};
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][j] + a_m.mat[i][j];
			}
		}
		return t_m;
	}

	Matrix3 Matrix3::Subtract(const float& a_a) const
	{
		Matrix3 t_m{};
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][j] - a_a;
			}
		}
		return t_m;
	}

	Matrix3 Matrix3::Subtract(const Matrix3& a_m) const
	{
		Matrix3 t_m{};
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][j] - a_m.mat[i][j];
			}
		}
		return t_m;
	}

	Matrix3 Matrix3::Product(const float& a_a) const
	{
		Matrix3 t_m{};
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][j] * a_a;
			}
		}
		return t_m;
	}

	Matrix3 Matrix3::Product(const Matrix3& a_m) const
	{
		Matrix3 t_m{};
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][0] * a_m.mat[0][j] + a_m.mat[i][1] * a_m.mat[1][j] + a_m.mat[i][2] * a_m.mat[2][
					j];
			}
		}
		return t_m;
	}

	Matrix3 Matrix3::Divide(const float& a_a) const
	{
		if (a_a <= PRECISION)
			throw std::invalid_argument("Error: Trying to divide by zero!");

		Matrix3 t_m{};
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][j] / a_a;
			}
		}
		return t_m;
	}

	Matrix3 Matrix3::Divide(const Matrix3& a_m) const
	{
		Matrix3 t_m{};
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[i][j] / a_m.mat[i][j];
			}
		}
		return t_m;
	}

	Matrix3 Matrix3::Opposite() const
	{
		const Matrix3 t_m{*this};
		return t_m * -1;
	}

	Matrix3 Matrix3::Transpose() const
	{
		Matrix3 t_m{};
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				t_m.mat[i][j] = mat[j][i];
			}
		}
		return t_m;
	}

	float Matrix3::Trace() const
	{
		return mat[0][0] + mat[1][1] + mat[2][2];
	}

	Matrix3 Matrix3::operator+(const float& a_a) const
	{
		return Add(a_a);
	}

	Matrix3 Matrix3::operator+(const Matrix3& a_m) const
	{
		return Add(a_m);
	}

	Matrix3 Matrix3::operator-(const float& a_a) const
	{
		return Subtract(a_a);
	}

	Matrix3 Matrix3::operator-(const Matrix3& a_m) const
	{
		return Subtract(a_m);
	}

	Matrix3 Matrix3::operator*(const float& a_a) const
	{
		return Product(a_a);
	}

	Matrix3 Matrix3::operator*(const Matrix3& a_m) const
	{
		return Product(a_m);
	}

	Matrix3 Matrix3::operator/(const float& a_a) const
	{
		return Divide(a_a);
	}

	Matrix3 Matrix3::operator/(const Matrix3& a_m) const
	{
		return Divide(a_m);
	}

	void Matrix3::operator+=(const float& a_a)
	{
		*this = *this + a_a;
	}

	void Matrix3::operator+=(const Matrix3& a_m)
	{
		*this = *this + a_m;
	}

	void Matrix3::operator*=(const float& a_a)
	{
		*this = *this * a_a;
	}

	void Matrix3::operator*=(const Matrix3& a_m)
	{
		*this = *this * a_m;
	}

	void Matrix3::operator-=(const float& a_a)
	{
		*this = *this - a_a;
	}

	void Matrix3::operator-=(const Matrix3& a_m)
	{
		*this = *this - a_m;
	}

	void Matrix3::operator/=(const float& a_a)
	{
		*this = *this / a_a;
	}

	void Matrix3::operator/=(const Matrix3& a_m)
	{
		*this = *this / a_m;
	}

	bool Matrix3::operator==(const float& a_a) const
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (mat[i][j] != a_a)
					return false;
			}
		}
		return true;
	}

	bool Matrix3::operator==(const Matrix3& a_m) const
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (mat[i][j] != a_m.mat[i][j])
					return false;
			}
		}
		return true;
	}

	bool Matrix3::operator!=(const float& a_a) const
	{
		return !(*this == a_a);
	}

	bool Matrix3::operator!=(const Matrix3& a_m) const
	{
		return !(*this == a_m);
	}

	void Matrix3::Print() const
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
