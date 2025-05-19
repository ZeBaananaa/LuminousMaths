#include "Matrix4.hpp"

#include <cmath>

#include "MathUtils.hpp"

#include "Vector3.hpp"

#include <iostream>

#include "Quaternion.hpp"

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

	Matrix4 Matrix4::Rotation(const Quaternion& a_quat)
	{
		const float xx = a_quat.x * a_quat.x;
		const float yy = a_quat.y * a_quat.y;
		const float zz = a_quat.z * a_quat.z;
		const float xy = a_quat.x * a_quat.y;
		const float xz = a_quat.x * a_quat.z;
		const float yz = a_quat.y * a_quat.z;
		const float wx = a_quat.w * a_quat.x;
		const float wy = a_quat.w * a_quat.y;
		const float wz = a_quat.w * a_quat.z;

		Matrix4 l_result = identity;
		l_result.mat[0][0] = 1.0f - 2.0f * (yy + zz);
		l_result.mat[0][1] = 2.0f * (xy - wz);
		l_result.mat[0][2] = 2.0f * (xz + wy);
		l_result.mat[0][3] = 0.0f;

		l_result.mat[1][0] = 2.0f * (xy + wz);
		l_result.mat[1][1] = 1.0f - 2.0f * (xx + zz);
		l_result.mat[1][2] = 2.0f * (yz - wx);
		l_result.mat[1][3] = 0.0f;

		l_result.mat[2][0] = 2.0f * (xz - wy);
		l_result.mat[2][1] = 2.0f * (yz + wx);
		l_result.mat[2][2] = 1.0f - 2.0f * (xx + yy);
		l_result.mat[2][3] = 0.0f;

		l_result.mat[3][0] = 0.0f;
		l_result.mat[3][1] = 0.0f;
		l_result.mat[3][2] = 0.0f;
		l_result.mat[3][3] = 1.0f;

		return l_result;
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

	Matrix4 Matrix4::TRS(const Maths::Vector3& a_translation, const Maths::Quaternion& a_rotation, const Maths::Vector3& a_scale)
	{
		Matrix4 l_mat = Translation(a_translation) *
						Rotation(a_rotation) *
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
		return Matrix4(mat) * -1;
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
		const Matrix4 l_transpose = Transpose();
		return (l_transpose * *this) == identity;
	}

	bool Matrix4::Decompose(Vector3& a_outTranslation, Quaternion& a_outRotation, Vector3& a_outScale) const
	{
		a_outTranslation = { mat[0][3], mat[1][3], mat[2][3] };

		Vector3 l_xAxis = { mat[0][0], mat[0][1], mat[0][2] };
		Vector3 l_yAxis = { mat[1][0], mat[1][1], mat[1][2] };
		Vector3 l_zAxis = { mat[2][0], mat[2][1], mat[2][2] };

		a_outScale.x = l_xAxis.Length();
		a_outScale.y = l_yAxis.Length();
		a_outScale.z = l_zAxis.Length();

		if (a_outScale.x != 0.f) l_xAxis /= a_outScale.x;
		if (a_outScale.y != 0.f) l_yAxis /= a_outScale.y;
		if (a_outScale.z != 0.f) l_zAxis /= a_outScale.z;

		Matrix4 l_rotationMatrix;
		l_rotationMatrix.mat[0][0] = l_xAxis.x; l_rotationMatrix.mat[0][1] = l_xAxis.y; l_rotationMatrix.mat[0][2] = l_xAxis.z;
		l_rotationMatrix.mat[1][0] = l_yAxis.x; l_rotationMatrix.mat[1][1] = l_yAxis.y; l_rotationMatrix.mat[1][2] = l_yAxis.z;
		l_rotationMatrix.mat[2][0] = l_zAxis.x; l_rotationMatrix.mat[2][1] = l_zAxis.y; l_rotationMatrix.mat[2][2] = l_zAxis.z;

		a_outRotation = Quaternion::FromMatrix(l_rotationMatrix);

		return true;
	}

	float Matrix4::Trace() const
	{
		return mat[0][0] + mat[1][1] + mat[2][2] + mat[3][3];
	}

    Matrix4 Matrix4::Inverse() const
	{
		const auto& m = mat;
		Matrix4 inv;

		inv.mat[0][0] =  m[1][1]*m[2][2]*m[3][3] - m[1][1]*m[2][3]*m[3][2] - m[2][1]*m[1][2]*m[3][3]
					   + m[2][1]*m[1][3]*m[3][2] + m[3][1]*m[1][2]*m[2][3] - m[3][1]*m[1][3]*m[2][2];

		inv.mat[0][1] = -m[0][1]*m[2][2]*m[3][3] + m[0][1]*m[2][3]*m[3][2] + m[2][1]*m[0][2]*m[3][3]
					   - m[2][1]*m[0][3]*m[3][2] - m[3][1]*m[0][2]*m[2][3] + m[3][1]*m[0][3]*m[2][2];

		inv.mat[0][2] =  m[0][1]*m[1][2]*m[3][3] - m[0][1]*m[1][3]*m[3][2] - m[1][1]*m[0][2]*m[3][3]
					   + m[1][1]*m[0][3]*m[3][2] + m[3][1]*m[0][2]*m[1][3] - m[3][1]*m[0][3]*m[1][2];

		inv.mat[0][3] = -m[0][1]*m[1][2]*m[2][3] + m[0][1]*m[1][3]*m[2][2] + m[1][1]*m[0][2]*m[2][3]
					   - m[1][1]*m[0][3]*m[2][2] - m[2][1]*m[0][2]*m[1][3] + m[2][1]*m[0][3]*m[1][2];

		inv.mat[1][0] = -m[1][0]*m[2][2]*m[3][3] + m[1][0]*m[2][3]*m[3][2] + m[2][0]*m[1][2]*m[3][3]
					   - m[2][0]*m[1][3]*m[3][2] - m[3][0]*m[1][2]*m[2][3] + m[3][0]*m[1][3]*m[2][2];

		inv.mat[1][1] =  m[0][0]*m[2][2]*m[3][3] - m[0][0]*m[2][3]*m[3][2] - m[2][0]*m[0][2]*m[3][3]
					   + m[2][0]*m[0][3]*m[3][2] + m[3][0]*m[0][2]*m[2][3] - m[3][0]*m[0][3]*m[2][2];

		inv.mat[1][2] = -m[0][0]*m[1][2]*m[3][3] + m[0][0]*m[1][3]*m[3][2] + m[1][0]*m[0][2]*m[3][3]
					   - m[1][0]*m[0][3]*m[3][2] - m[3][0]*m[0][2]*m[1][3] + m[3][0]*m[0][3]*m[1][2];

		inv.mat[1][3] =  m[0][0]*m[1][2]*m[2][3] - m[0][0]*m[1][3]*m[2][2] - m[1][0]*m[0][2]*m[2][3]
					   + m[1][0]*m[0][3]*m[2][2] + m[2][0]*m[0][2]*m[1][3] - m[2][0]*m[0][3]*m[1][2];

		inv.mat[2][0] =  m[1][0]*m[2][1]*m[3][3] - m[1][0]*m[2][3]*m[3][1] - m[2][0]*m[1][1]*m[3][3]
					   + m[2][0]*m[1][3]*m[3][1] + m[3][0]*m[1][1]*m[2][3] - m[3][0]*m[1][3]*m[2][1];

		inv.mat[2][1] = -m[0][0]*m[2][1]*m[3][3] + m[0][0]*m[2][3]*m[3][1] + m[2][0]*m[0][1]*m[3][3]
					   - m[2][0]*m[0][3]*m[3][1] - m[3][0]*m[0][1]*m[2][3] + m[3][0]*m[0][3]*m[2][1];

		inv.mat[2][2] =  m[0][0]*m[1][1]*m[3][3] - m[0][0]*m[1][3]*m[3][1] - m[1][0]*m[0][1]*m[3][3]
					   + m[1][0]*m[0][3]*m[3][1] + m[3][0]*m[0][1]*m[1][3] - m[3][0]*m[0][3]*m[1][1];

		inv.mat[2][3] = -m[0][0]*m[1][1]*m[2][3] + m[0][0]*m[1][3]*m[2][1] + m[1][0]*m[0][1]*m[2][3]
					   - m[1][0]*m[0][3]*m[2][1] - m[2][0]*m[0][1]*m[1][3] + m[2][0]*m[0][3]*m[1][1];

		inv.mat[3][0] = -m[1][0]*m[2][1]*m[3][2] + m[1][0]*m[2][2]*m[3][1] + m[2][0]*m[1][1]*m[3][2]
					   - m[2][0]*m[1][2]*m[3][1] - m[3][0]*m[1][1]*m[2][2] + m[3][0]*m[1][2]*m[2][1];

		inv.mat[3][1] =  m[0][0]*m[2][1]*m[3][2] - m[0][0]*m[2][2]*m[3][1] - m[2][0]*m[0][1]*m[3][2]
					   + m[2][0]*m[0][2]*m[3][1] + m[3][0]*m[0][1]*m[2][2] - m[3][0]*m[0][2]*m[2][1];

		inv.mat[3][2] = -m[0][0]*m[1][1]*m[3][2] + m[0][0]*m[1][2]*m[3][1] + m[1][0]*m[0][1]*m[3][2]
					   - m[1][0]*m[0][2]*m[3][1] - m[3][0]*m[0][1]*m[1][2] + m[3][0]*m[0][2]*m[1][1];

		inv.mat[3][3] =  m[0][0]*m[1][1]*m[2][2] - m[0][0]*m[1][2]*m[2][1] - m[1][0]*m[0][1]*m[2][2]
					   + m[1][0]*m[0][2]*m[2][1] + m[2][0]*m[0][1]*m[1][2] - m[2][0]*m[0][2]*m[1][1];

		float det = m[0][0] * inv.mat[0][0] + m[0][1] * inv.mat[1][0] + m[0][2] * inv.mat[2][0] + m[0][3] * inv.mat[3][0];

		if (det == 0.0f)
		{
			throw std::runtime_error("Matrix4::Inverse: determinant is zero, matrix not invertible.");
		}

		float invDet = 1.0f / det;

		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				inv.mat[i][j] *= invDet;

		return inv;
	}


    Matrix4 Matrix4::InverseTRS() const
    {
		Matrix4 result;

		Vector3 col0 = Vector3(mat[0][0], mat[1][0], mat[2][0]);
		Vector3 col1 = Vector3(mat[0][1], mat[1][1], mat[2][1]);
		Vector3 col2 = Vector3(mat[0][2], mat[1][2], mat[2][2]);

		float sx = col0.Length();
		float sy = col1.Length();
		float sz = col2.Length();

		if (sx == 0.0f || sy == 0.0f || sz == 0.0f)
			throw std::runtime_error("Matrix4::InverseTRS: Scale component is zero.");

		col0 /= sx;
		col1 /= sy;
		col2 /= sz;

		Matrix4 rotationInv;
		rotationInv.mat[0][0] = col0.x;
		rotationInv.mat[0][1] = col0.y;
		rotationInv.mat[0][2] = col0.z;
		rotationInv.mat[1][0] = col1.x;
		rotationInv.mat[1][1] = col1.y;
		rotationInv.mat[1][2] = col1.z;
		rotationInv.mat[2][0] = col2.x;
		rotationInv.mat[2][1] = col2.y;
		rotationInv.mat[2][2] = col2.z;

		rotationInv.mat[0][0] /= sx;
		rotationInv.mat[1][1] /= sy;
		rotationInv.mat[2][2] /= sz;

		Vector3 translation(mat[0][3], mat[1][3], mat[2][3]);
		Vector3 invTranslation = (rotationInv * translation) * -1;

		result = rotationInv;
		result.mat[0][3] = invTranslation.x;
		result.mat[1][3] = invTranslation.y;
		result.mat[2][3] = invTranslation.z;
		result.mat[3][0] = result.mat[3][1] = result.mat[3][2] = 0.0f;
		result.mat[3][3] = 1.0f;

		return result;
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
