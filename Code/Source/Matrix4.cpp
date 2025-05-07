#include "Matrix4.hpp"

#include <cmath>

#include "MathUtils.hpp"

#include "Vector3.hpp"

#include <iostream>

namespace Maths
{
	Matrix4 Matrix4::zero = Matrix4(0.0f);
	Matrix4 Matrix4::identity = Matrix4({{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}});

	Matrix4 Matrix4::Translation(const Maths::Vector3& a_v)
	{
		Matrix4 l_mat = identity;
		l_mat.mat[0][3] = a_v.x;
		l_mat.mat[1][3] = a_v.y;
		l_mat.mat[2][3] = a_v.z;
		return l_mat;
	}

	Matrix4 Matrix4::Scale(const Maths::Vector3& a_v)
	{
		Matrix4 l_mat = identity;
		l_mat.mat[0][0] = a_v.x;
		l_mat.mat[1][1] = a_v.y;
		l_mat.mat[2][2] = a_v.z;
		return l_mat;
	}

	Matrix4 Matrix4::RotationX(const float& a_angle)
	{
		float l_radAngle = DegToRad(a_angle);

		Matrix4 l_mat = identity;
		float l_c = cos(l_radAngle);
		float l_s = sin(l_radAngle);
		l_mat.mat[1][1] = l_c;
		l_mat.mat[1][2] = l_s;
		l_mat.mat[2][1] = -l_s;
		l_mat.mat[2][2] = l_c;
		return l_mat;
	}

	Matrix4 Matrix4::RotationY(const float& a_angle)
	{
		float l_radAngle = DegToRad(a_angle);

		Matrix4 l_mat = identity;
		float l_c = cos(l_radAngle);
		float l_s = sin(l_radAngle);
		l_mat.mat[0][0] = l_c;
		l_mat.mat[0][2] = -l_s;
		l_mat.mat[2][0] = l_s;
		l_mat.mat[2][2] = l_c;
		return l_mat;
	}

	Matrix4 Matrix4::RotationZ(const float& a_angle)
	{
		float l_radAngle = DegToRad(a_angle);

		Matrix4 l_mat = identity;
		float l_c = cos(l_radAngle);
		float l_s = sin(l_radAngle);
		l_mat.mat[0][0] = l_c;
		l_mat.mat[0][1] = l_s;
		l_mat.mat[1][0] = -l_s;
		l_mat.mat[1][1] = l_c;
		return l_mat;
	}

	Matrix4 Matrix4::RotationXYZ(const Vector3& a_axisAngle)
	{
		Matrix4 l_finalRot = RotationX(a_axisAngle.x) *
			RotationY(a_axisAngle.y) *
			RotationZ(a_axisAngle.z);
		l_finalRot.RoundTiny();
		return l_finalRot;
	}

	Matrix4 Matrix4::RotationAxisAngle(const float& a_angle, const Vector3& a_axis)
	{
		float l_radAngle = DegToRad(a_angle);

		float l_c = cos(l_radAngle);
		float l_s = sin(l_radAngle);
		Vector3 l_normAxis = a_axis.Normalize();
		float l_t = 1.0f - l_c;


		Matrix4 l_mat = identity;
		l_mat.mat[0][0] = l_c + l_normAxis.x * l_normAxis.x * l_t;
		l_mat.mat[1][1] = l_c + l_normAxis.y * l_normAxis.y * l_t;
		l_mat.mat[2][2] = l_c + l_normAxis.z * l_normAxis.z * l_t;

		float l_tmp1 = l_normAxis.x * l_normAxis.y * l_t;
		float l_tmp2 = l_normAxis.z * l_s;
		l_mat.mat[1][0] = l_tmp1 + l_tmp2;
		l_mat.mat[0][1] = l_tmp1 - l_tmp2;
		l_tmp1 = l_normAxis.x * l_normAxis.z * l_t;
		l_tmp2 = l_normAxis.y * l_s;
		l_mat.mat[2][0] = l_tmp1 - l_tmp2;
		l_mat.mat[0][2] = l_tmp1 + l_tmp2;
		l_tmp1 = l_normAxis.y * l_normAxis.z * l_t;
		l_tmp2 = l_normAxis.x * l_s;
		l_mat.mat[2][1] = l_tmp1 + l_tmp2;
		l_mat.mat[1][2] = l_tmp1 - l_tmp2;

		return l_mat;
	}

	Matrix4 Matrix4::Rotate(const Matrix4& a_mat, const float& a_angle, const Vector3& a_axis)
	{
		return a_mat * RotationAxisAngle(a_angle, a_axis);
	}

	Matrix4 Matrix4::TRS(const Maths::Vector3& a_translation, const Maths::Vector3& a_rotation, const Maths::Vector3& a_scale)
	{
		Matrix4 l_mat = Translation(a_translation) *
		                RotationXYZ(a_rotation) *
		                Scale(a_scale);
		l_mat.RoundTiny();
		return l_mat;
	}

	Matrix4 Matrix4::TRS(const Maths::Matrix4& a_translation, const Maths::Matrix4& a_rotation, const Maths::Matrix4& a_scale)
	{
		Matrix4 l_mat = a_translation * a_rotation * a_scale;
		l_mat.RoundTiny();
		return l_mat;
	}

	Matrix4 Matrix4::LookAt(const Vector3& a_eye, const Vector3& a_center, const Vector3& a_up)
	{
		Vector3 l_fn = Vector3(a_center - a_eye).Normalize();
		Vector3 l_un = a_up.Normalize();
		Vector3 l_s = l_fn.CrossProduct(l_un).Normalize();
		Vector3 l_u = l_s.CrossProduct(l_fn);

		float l_seye = l_s.DotProduct(a_eye);
		float l_ueye = l_u.DotProduct(a_eye);
		float l_feye = l_fn.DotProduct(a_eye);

		Matrix4 l_look = Matrix4
			({
				{ l_s.x,l_s.y,l_s.z,-l_seye },
				{ l_u.x,l_u.y,l_u.z,-l_ueye },
				{ -l_fn.x,-l_fn.y,-l_fn.z,l_feye },
				{ 0.0f,0.0f,0.0f,1.0f },
			}
			);
		return l_look;
	}


	Matrix4 Matrix4::Perspective(const float& a_fovY, const float& a_aspect, const float& a_zNear, const float& a_zFar)
	{
		const float fovRad = DegToRad(a_fovY);
		const float tanHalfFov = tanf(fovRad / 2.0f);

		return Matrix4({
			{ 1.0f / (a_aspect * tanHalfFov), 0.0f, 0.0f, 0.0f },
			{ 0.0f, 1.0f / tanHalfFov, 0.0f, 0.0f },
			{ 0.0f, 0.0f, a_zFar / (a_zNear - a_zFar), -1.0f },
			{ 0.0f, 0.0f, (a_zFar * a_zNear) / (a_zNear - a_zFar), 0.0f }
		});
	}

	Matrix4::Matrix4(const float& a_a)
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				mat[i][j] = (i == j) ? a_a : 0.0f;
			}
		}
	}

	Matrix4::Matrix4(const float (&a_mat)[4][4])
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				mat[i][j] = a_mat[i][j];
			}
		}
	}

	Matrix4 Matrix4::Add(const float& a_a) const
	{
		Matrix4 l_m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				l_m.mat[i][j] = mat[i][j] + a_a;
			}
		}
		return l_m;
	}

	Matrix4::Matrix4(const std::array<std::array<float, 4>, 4>& a_mat)
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				mat[i][j] = a_mat[i][j];
			}
		}
	}

	Matrix4 Matrix4::Add(const Matrix4& a_m) const
	{
		Matrix4 l_m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				l_m.mat[i][j] = mat[i][j] + a_m.mat[i][j];
			}
		}
		return l_m;
	}

	Matrix4 Matrix4::Subtract(const float& a_a) const
	{
		Matrix4 l_m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				l_m.mat[i][j] = mat[i][j] - a_a;
			}
		}
		return l_m;
	}


	Matrix4 Matrix4::Subtract(const Matrix4& a_m) const
	{
		Matrix4 l_m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				l_m.mat[i][j] = mat[i][j] - a_m.mat[i][j];
			}
		}
		return l_m;
	}

	Matrix4 Matrix4::Product(const float& a_a) const
	{
		Matrix4 l_m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				l_m.mat[i][j] = mat[i][j] * a_a;
			}
		}
		return l_m;
	}

	Matrix4 Matrix4::Product(const Matrix4& a_m) const
	{
		Matrix4 l_m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				l_m.mat[i][j] = 0;
				for (int k = 0; k < 4; ++k)
				{
					l_m.mat[i][j] += mat[i][k] * a_m.mat[k][j];
				}
			}
		}
		return l_m;
	}

	Maths::Vector3 Matrix4::Product(const Maths::Vector3& a_m) const
	{
		float t_vec[4] = { a_m.x, a_m.y, a_m.z, 1.0f };
		float t_result[4] = { 0, 0, 0, 0 };

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				t_result[i] += mat[i][j] * t_vec[j];
			}
		}
		return Maths::Vector3(t_result[0], t_result[1], t_result[2]);
	}

	Matrix4 Matrix4::Divide(const float& a_a) const
	{
		Matrix4 l_m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				l_m.mat[i][j] = mat[i][j] / a_a;
			}
		}
		return l_m;
	}

	Matrix4 Matrix4::Divide(const Matrix4& a_m) const
	{
		Matrix4 l_m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				l_m.mat[i][j] = mat[i][j] / a_m.mat[i][j];
			}
		}
		return l_m;
	}

	Matrix4 Matrix4::Opposite() const
	{
		Matrix4 l_m = Matrix4(mat);
		return l_m * -1;
	}

	Matrix4 Matrix4::Transpose() const
	{
		Matrix4 l_m = Matrix4();
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				l_m.mat[i][j] = mat[j][i];
			}
		}
		return l_m;
	}

	bool Matrix4::IsOrthogonal() const
	{
		Matrix4 l_transpose = Transpose();
		return (l_transpose * *this) == identity;
	}

	float Matrix4::Trace() const
	{
		return mat[0][0] + mat[1][1] + mat[2][2] + mat[3][3];
	}

	Matrix4 Matrix4::Inverse() const
	{
		if (IsOrthogonal())
		{
			return Transpose();
		}
		std::cout << "Matrix isn't orthogonal." << '\n';
		return *this;
	}


	Matrix4 Matrix4::operator+(const float& a_a) const
	{
		return Add(a_a);
	}

	Matrix4 Matrix4::operator+(const Matrix4& a_m) const
	{
		return Add(a_m);
	}

	Matrix4 Matrix4::operator-(const float& a_a) const
	{
		return Subtract(a_a);
	}

	Matrix4 Matrix4::operator-(const Matrix4& a_m) const
	{
		return Subtract(a_m);
	}

	Matrix4 Matrix4::operator*(const float& a_a) const
	{
		return Product(a_a);
	}

	Matrix4 Matrix4::operator*(const Matrix4& a_m) const
	{
		return Product(a_m);
	}

	Vector3 Matrix4::operator*(const Vector3& a_m) const
	{
		return Product(a_m);
	}

	Matrix4 Matrix4::operator/(const float& a_a) const
	{
		return Divide(a_a);
	}

	Matrix4 Matrix4::operator/(const Matrix4& a_m) const
	{
		return Divide(a_m);
	}

	void Matrix4::operator+=(const float& a_a)
	{
		*this = *this + a_a;
	}

	void Matrix4::operator+=(const Matrix4& a_m)
	{
		*this = *this + a_m;
	}

	void Matrix4::operator*=(const float& a_a)
	{
		*this = *this * a_a;
	}

	void Matrix4::operator*=(const Matrix4& a_m)
	{
		*this = *this * a_m;
	}

	void Matrix4::operator-=(const float& a_a)
	{
		*this = *this - a_a;
	}

	void Matrix4::operator-=(const Matrix4& a_m)
	{
		*this = *this - a_m;
	}

	void Matrix4::operator/=(const float& a_a)
	{
		*this = *this / a_a;
	}

	void Matrix4::operator/=(const Matrix4& a_m)
	{
		*this = *this / a_m;
	}

	bool Matrix4::operator==(const float& a_a) const
	{
		bool l_condition = true;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (mat[i][j] != a_a)
					l_condition = false;
			}
			if (!l_condition)
				break;
		}
		return l_condition;
	}

	bool Matrix4::operator==(const Matrix4& a_m) const
	{
		bool l_condition = true;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (mat[i][j] != a_m.mat[i][j])
					l_condition = false;
			}
			if (!l_condition)
				break;
		}
		return l_condition;
	}

	bool Matrix4::operator!=(const float& a_a) const
	{
		bool l_condition = true;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (mat[i][j] == a_a)
					l_condition = false;
			}
			if (!l_condition)
				break;
		}
		return l_condition;
	}

	bool Matrix4::operator!=(const Matrix4& a_m) const
	{
		bool l_condition = true;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (mat[i][j] == a_m.mat[i][j])
					l_condition = false;
			}
			if (!l_condition)
				break;
		}
		return l_condition;
	}

	void Matrix4::RoundTiny()
	{
		float l_epsilon = 1e-6f;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (fabs(mat[i][j]) < l_epsilon)
				{
					mat[i][j] = 0.0f;
				}
			}
		}
	}


	void Matrix4::Print() const
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
