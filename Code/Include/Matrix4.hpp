#pragma once

#include <array>
#include "Vector3.hpp"

namespace Maths
{
	class Vector4;

	class Matrix4
	{
	public:
		std::array<std::array<float, 4>, 4> mat = {
			{
				{0.0f, 0.0f, 0.0f, 0.0f},
				{0.0f, 0.0f, 0.0f, 0.0f},
				{0.0f, 0.0f, 0.0f, 0.0f},
				{0.0f, 0.0f, 0.0f, 0.0f}
			}
		};

		Matrix4() = default;

		explicit Matrix4(const float& a_a);

		explicit Matrix4(const float (&a_mat)[4][4]);

		explicit Matrix4(const std::array<std::array<float, 4>, 4>& a_mat);

		inline void SetMatrixValue(int a_index1, int a_index2, float a_value) { mat[a_index1][a_index2] = a_value; }

		inline Vector3 GetTranslation() const { return Vector3 {mat[3][0], mat[3][1], mat[3][2] }; }

		inline Vector3 GetScale() const
		{
			float l_scaleX = Maths::Vector3{ mat[0][0], mat[0][1], mat[0][2] }.Length();
			float l_scaleY = Maths::Vector3{ mat[1][0], mat[1][1], mat[1][2] }.Length();
			float l_scaleZ = Maths::Vector3{ mat[2][0], mat[2][1], mat[2][2] }.Length();

			return { l_scaleX, l_scaleY, l_scaleZ };
		}

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

		bool Decompose(Vector3& a_outTranslation, Quaternion& a_outRotation, Vector3& a_outScale) const;

		float Trace() const;

		Matrix4 Inverse() const;

		static Matrix4 Translation(const Vector3& a_v);

		static Matrix4 Scale(const Vector3& a_v);

		static Matrix4 RotationX(const float& a_angle);

		static Matrix4 RotationY(const float& a_angle);

		static Matrix4 RotationZ(const float& a_angle);

		static Matrix4 RotationAxisAngle(const float& a_angle, const Vector3& a_axis);

		static Matrix4 RotationXYZ(const Vector3& a_axisAngle);

		static Matrix4 Rotate(const Matrix4& a_mat, const float& a_angle, const Vector3& a_axis);

		static Matrix4 TRS(const Vector3& a_translation, const Vector3& a_rotation, const Vector3& a_scale);

		static Matrix4 TRS(const Matrix4& a_translation, const Matrix4& a_rotation, const Matrix4& a_scale);

		static Matrix4 LookAt(const Vector3& a_eye, const Vector3& a_center, const Vector3& a_up);

		static Matrix4 Perspective(const float& a_fovY, const float& a_aspect, const float& a_zNear, const float& a_zFar);

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
