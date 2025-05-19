#include "Quaternion.hpp"

#include <cmath>

#include <iostream>
#include "MathUtils.hpp"
#include "Matrix4.hpp"
#include "Vector3.hpp"

namespace Maths
{

	Quaternion::Quaternion(const float& a_x, const float& a_y, const float& a_z, const float& a_w)
	{
		w = a_w;
		x = a_x;
		y = a_y;
		z = a_z;
	}

	Quaternion::Quaternion(const Vector3& a_v)
	{
		x = a_v.x;
		y = a_v.y;
		z = a_v.z;
		w = 0.0f;
	}

	Quaternion Quaternion::Add(const Quaternion& a_q) const
	{
		return Quaternion(x + a_q.x, y + a_q.y, z + a_q.z, w + a_q.w);
	}

	Quaternion Quaternion::Subtract(const Quaternion& a_q) const
	{
		return Quaternion(x - a_q.x, y - a_q.y, z - a_q.z, w - a_q.w);
	}

	Quaternion Quaternion::Product(const Quaternion& a_q) const
	{
		return Quaternion
		(
			w * a_q.x + x * a_q.w + y * a_q.z - z * a_q.y,
			w * a_q.y - x * a_q.z + y * a_q.w + z * a_q.x,
			w * a_q.z + x * a_q.y - y * a_q.x + z * a_q.w,
			w * a_q.w - x * a_q.x - y * a_q.y - z * a_q.z

		);
	}

	Quaternion Quaternion::Product(const float a_a) const
	{
		return Quaternion(x * a_a, y * a_a, z * a_a, w * a_a);
	}

	float Quaternion::Length() const
	{
		return Sqrt((x * x) + (y * y) + (z * z) + (w * w));
	}

	Quaternion Quaternion::Normalize() const
	{
		return Quaternion(x / Length(), y / Length(), z / Length(), w / Length());
	}

	Quaternion Quaternion::Conjugate() const
	{
		return Quaternion(-x, -y, -z, w);
	}

	Quaternion Quaternion::Opposite() const
	{
		return Quaternion(-x, -y, -z, -w);
	}

	Vector3 Quaternion::ToEulerAngles(bool a_toDeg) const
	{
		const float l_ysqr = y * y;

		const float l_0 = 2.0f * (w * x + y * z);
		const float l_1 = 1.0f - 2.0f * (x * x + l_ysqr);
		const float l_roll = atan2f(l_0, l_1);

		float l_2 = 2.0f * (w * y - z * x);
		if (l_2 < -1.0f) { l_2 = -1.0f; } else if (l_2 > 1.0f) { l_2 = 1.0f; }
		const float l_pitch = asinf(l_2);

		const float l_3 = 2.0f * (w * z + x * y);
		const float l_4 = 1.0f - 2.0f * (l_ysqr + z * z);
		const float l_yaw = atan2f(l_3, l_4);

		Vector3 l_return = Vector3(l_roll, l_pitch, l_yaw);

		if (a_toDeg)
			l_return = Vector3(RadToDeg(l_roll), RadToDeg(l_pitch), RadToDeg(l_yaw));
		return l_return;
	}


	Quaternion Quaternion::Inverse() const
	{
		const float l_normSq = x * x + y * y + z * z + w * w;
		if (l_normSq == 0.0f)
			return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);

		const Quaternion l_conj = Conjugate();
		return Quaternion(l_conj.x / l_normSq, l_conj.y / l_normSq, l_conj.z / l_normSq, l_conj.w / l_normSq);
	}


	void Quaternion::Print() const
	{
		std::cout << w << ", " << x << ", " << y << ", " << z << '\n';
	}

    Quaternion Quaternion::FromMatrix(const Matrix4& a_mat)
    {
		Vector3 xAxis = { a_mat.mat[0][0], a_mat.mat[0][1], a_mat.mat[0][2] };
		Vector3 yAxis = { a_mat.mat[1][0], a_mat.mat[1][1], a_mat.mat[1][2] };
		Vector3 zAxis = { a_mat.mat[2][0], a_mat.mat[2][1], a_mat.mat[2][2] };

        float scaleX = xAxis.Length();
        float scaleY = yAxis.Length();
        float scaleZ = zAxis.Length();

        constexpr float epsilon = 1e-6f;
        if (scaleX < epsilon)
            scaleX = 1.0f;
        if (scaleY < epsilon)
            scaleY = 1.0f;
        if (scaleZ < epsilon)
            scaleZ = 1.0f;

        Matrix4 rotMat = a_mat;
        for (int i = 0; i < 3; ++i)
        {
            rotMat.mat[0][i] /= scaleX;
            rotMat.mat[1][i] /= scaleY;
            rotMat.mat[2][i] /= scaleZ;
        }

        float trace = rotMat.mat[0][0] + rotMat.mat[1][1] + rotMat.mat[2][2];
        float scalar;
        Quaternion quat;

        if (trace > 0.0f)
        {
            scalar = 0.5f / std::sqrt(trace + 1.0f);
            quat.w = 0.25f / scalar;
            quat.x = (rotMat.mat[2][1] - rotMat.mat[1][2]) * scalar;
            quat.y = (rotMat.mat[0][2] - rotMat.mat[2][0]) * scalar;
            quat.z = (rotMat.mat[1][0] - rotMat.mat[0][1]) * scalar;
        } else
        {
            if (rotMat.mat[0][0] > rotMat.mat[1][1] && rotMat.mat[0][0] > rotMat.mat[2][2])
            {
                scalar = 2.0f * std::sqrt(1.0f + rotMat.mat[0][0] - rotMat.mat[1][1] - rotMat.mat[2][2]);
                quat.w = (rotMat.mat[2][1] - rotMat.mat[1][2]) / scalar;
                quat.x = 0.25f * scalar;
                quat.y = (rotMat.mat[0][1] + rotMat.mat[1][0]) / scalar;
                quat.z = (rotMat.mat[0][2] + rotMat.mat[2][0]) / scalar;
            } else if (rotMat.mat[1][1] > rotMat.mat[2][2])
            {
                scalar = 2.0f * std::sqrt(1.0f + rotMat.mat[1][1] - rotMat.mat[0][0] - rotMat.mat[2][2]);
                quat.w = (rotMat.mat[0][2] - rotMat.mat[2][0]) / scalar;
                quat.x = (rotMat.mat[0][1] + rotMat.mat[1][0]) / scalar;
                quat.y = 0.25f * scalar;
                quat.z = (rotMat.mat[1][2] + rotMat.mat[2][1]) / scalar;
            } else
            {
                scalar = 2.0f * std::sqrt(1.0f + rotMat.mat[2][2] - rotMat.mat[0][0] - rotMat.mat[1][1]);
                quat.w = (rotMat.mat[1][0] - rotMat.mat[0][1]) / scalar;
                quat.x = (rotMat.mat[0][2] + rotMat.mat[2][0]) / scalar;
                quat.y = (rotMat.mat[1][2] + rotMat.mat[2][1]) / scalar;
                quat.z = 0.25f * scalar;
            }
        }

        return quat.Normalize();
    }

	Quaternion Quaternion::FromEulerAngles(const Vector3& a_v)
	{
		const Vector3 l_radToVec = Vector3(DegToRad(a_v.z), DegToRad(a_v.y), DegToRad(a_v.x));

		const float l_cr = cosf(l_radToVec.z * 0.5f);
		const float l_sr = sinf(l_radToVec.z * 0.5f);
		const float l_cp = cosf(l_radToVec.y * 0.5f);
		const float l_sp = sinf(l_radToVec.y * 0.5f);
		const float l_cy = cosf(l_radToVec.x * 0.5f);
		const float l_sy = sinf(l_radToVec.x * 0.5f);

		const Quaternion l_q = Quaternion
		(
			l_sr * l_cp * l_cy - l_cr * l_sp * l_sy,
			l_cr * l_sp * l_cy + l_sr * l_cp * l_sy,
			l_cr * l_cp * l_sy - l_sr * l_sp * l_cy,
			l_cr * l_cp * l_cy + l_sr * l_sp * l_sy
		);

		return l_q;
	}

	Quaternion Quaternion::Slerp(const Quaternion& a_q1, const Quaternion& a_q2, const float a_t)
	{
		const Quaternion l_q1 = a_q1.Normalize();
		Quaternion l_q2 = a_q2.Normalize();

		float l_dot = l_q1.w * l_q2.w + l_q1.x * l_q2.x + l_q1.y * l_q2.y + l_q1.z * l_q2.z;

		if (l_dot < 0.0f)
		{
			l_q2 = l_q2 * -1.0f;
			l_dot = -l_dot;
		}

		if (constexpr float l_threshold = 0.9995f; l_dot > l_threshold)
		{
			const Quaternion result = l_q1 + (l_q2 - l_q1) * a_t;
			return result.Normalize();
		}

		const float l_theta_0 = acosf(l_dot);
		const float l_theta = l_theta_0 * a_t;

		const Quaternion q3 = (l_q2 - l_q1 * l_dot).Normalize();
		const Quaternion q5 = l_q1 * cosf(l_theta) + q3 * sinf(l_theta);

		return Quaternion(Precise(q5.x), Precise(q5.y), Precise(q5.z), Precise(q5.w));
	}


	Quaternion Quaternion::AngleAxis(const float& a_angle, const Vector3& a_axis)
	{
		const float l_halfAngle = a_angle * 0.5f;
		const float l_sin = sin(l_halfAngle);
		const Vector3 l_axisNormalized = a_axis.Normalize();

		return Quaternion { cos(l_halfAngle), l_axisNormalized.x * l_sin, l_axisNormalized.y * l_sin, l_axisNormalized.z * l_sin };
	}


	Quaternion Quaternion::operator+(const Quaternion& a_q) const
	{
		return Add(a_q);
	}

	Quaternion Quaternion::operator-(const Quaternion& a_q) const
	{
		return Subtract(a_q);
	}

	Quaternion Quaternion::operator*(const float& a_a) const
	{
		return Product(a_a);
	}

	Quaternion Quaternion::operator*(const Quaternion& a_q) const
	{
		return Product(a_q);
	}

	void Quaternion::operator+=(const Quaternion& a_v)
	{
		*this = Add(a_v);
	}

	void Quaternion::operator*=(const float& a_a)
	{
		*this = Product(a_a);
	}

	void Quaternion::operator*=(const Quaternion& a_v)
	{
		*this = Product(a_v);
	}

	void Quaternion::operator-=(const Quaternion& a_v)
	{
		*this = Subtract(a_v);
	}

	bool Quaternion::operator==(const Quaternion& a_q) const
	{
		return x == a_q.x && y == a_q.y && z == a_q.z && w == a_q.w;
	}

	bool Quaternion::operator!=(const Quaternion& a_q) const
	{
		return !(x == a_q.x && y == a_q.y && z == a_q.z && w == a_q.w);
	}

	Quaternion Quaternion::Identity = Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
	Quaternion Quaternion::Zero = Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
	Quaternion Quaternion::One = Quaternion(1.0f, 0.0f, 0.0f, 0.0f);
}
