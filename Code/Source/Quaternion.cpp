#include "Quaternion.hpp"

#include <cmath>

#include "Vector3.hpp"
#include <iostream>
#include "Utils.hpp"


namespace Maths {
	Quaternion::Quaternion(float a_x, float a_y, float a_z, float a_w) {
		w = a_w;
		x = a_x;
		y = a_y;
		z = a_z;
	}

	Quaternion::Quaternion(Vector3 a_v) {
		x = a_v.x;
		y = a_v.y;
		z = a_v.z;
		w = 0.0f;
	}

	Quaternion Quaternion::Add(const Quaternion &a_q) const {
		return Quaternion(x + a_q.x, y + a_q.y, z + a_q.z, w + a_q.w);
	}

	Quaternion Quaternion::Substract(const Quaternion &a_q) const {
		return Quaternion(x - a_q.x, y - a_q.y, z - a_q.z, w - a_q.w);
	}

	Quaternion Quaternion::Product(const Quaternion &a_q) const {
		return Quaternion
		(
			w * a_q.x + x * a_q.w + y * a_q.z - z * a_q.y,
			w * a_q.y - x * a_q.z + y * a_q.w + z * a_q.x,
			w * a_q.z + x * a_q.y - y * a_q.x + z * a_q.w,
			w * a_q.w - x * a_q.x - y * a_q.y - z * a_q.z

		);
	}

	Quaternion Quaternion::Product(const float a_a) const {
		return Quaternion(x * a_a, y * a_a, z * a_a, w * a_a);
	}

	float Quaternion::Length() const {
		return Sqrt((x * x) + (y * y) + (z * z) + (w * w));
	}

	Quaternion Quaternion::Normalize() const {
		return Quaternion(x / Length(), y / Length(), z / Length(), w / Length());
	}

	Quaternion Quaternion::Conjugate() const {
		return Quaternion(-x, -y, -z, w);
	}

	Quaternion Quaternion::Opposite() const {
		return Quaternion(-x, -y, -z, -w);
	}

	Vector3 Quaternion::ToEulerAngles() const {
		float t_ysqr = y * y;

		float t_0 = 2.0f * (w * x + y * z);
		float t_1 = 1.0f - 2.0f * (x * x + t_ysqr);
		float t_roll = atan2f(t_0, t_1);

		float t_2 = 2.0f * (w * y - z * x);
		if (t_2 < -1.0f) { t_2 = -1.0f; } else if (t_2 > 1.0f) { t_2 = 1.0f; }
		float t_pitch = asinf(t_2);

		float t_3 = 2.0f * (w * z + x * y);
		float t_4 = 1.0f - 2.0f * (t_ysqr + z * z);
		float t_yaw = atan2f(t_3, t_4);

		return Vector3(Maths::RadToDeg(t_roll), Maths::RadToDeg(t_pitch), Maths::RadToDeg(t_yaw));
	}


	void Quaternion::Print() const {
		std::cout << w << ", " << x << ", " << y << ", " << z << '\n';
	}

	Quaternion Quaternion::FromEulerAngles(const Vector3 &a_v) {
		Vector3 t_radvec = Vector3(Maths::DegToRad(a_v.x), Maths::DegToRad(a_v.y), Maths::DegToRad(a_v.z));

		const float t_cr = cos(t_radvec.z * 0.5f);
		const float t_sr = sin(t_radvec.z * 0.5f);
		const float t_cp = cos(t_radvec.y * 0.5f);
		const float t_sp = sin(t_radvec.y * 0.5f);
		const float t_cy = cos(t_radvec.x * 0.5f);
		const float t_sy = sin(t_radvec.x * 0.5f);

		Quaternion t_q = Quaternion
		(
			t_sr * t_cp * t_cy - t_cr * t_sp * t_sy,
			t_cr * t_sp * t_cy + t_sr * t_cp * t_sy,
			t_cr * t_cp * t_sy - t_sr * t_sp * t_cy,
			t_cr * t_cp * t_cy + t_sr * t_sp * t_sy
		);

		return t_q;
	}

	Quaternion Quaternion::Slerp(const Quaternion &a_q1, const Quaternion &a_q2, float a_t) {
		Quaternion t_q1 = a_q1.Normalize();
		Quaternion t_q2 = a_q2.Normalize();

		float t_dot = t_q1.w * t_q2.w + t_q1.x * t_q2.x + t_q1.y * t_q2.y + t_q1.z * t_q2.z;

		if (t_dot < 0.0f) {
			t_q2 = t_q2 * -1.0f;
			t_dot = -t_dot;
		}

		const float t_threshold = 0.9995f;
		if (t_dot > t_threshold) {
			Quaternion result = t_q1 + (t_q2 - t_q1) * a_t;
			return result.Normalize();
		}

		float t_theta_0 = acosf(t_dot);
		float t_theta = t_theta_0 * a_t;

		Quaternion q3 = (t_q2 - t_q1 * t_dot).Normalize();
		Quaternion q5 = t_q1 * cosf(t_theta) + q3 * sinf(t_theta);

		return Quaternion(Maths::Precise(q5.x), Maths::Precise(q5.y), Maths::Precise(q5.z), Maths::Precise(q5.w));
	}

	Quaternion Quaternion::operator+(const Quaternion &a_q) const {
		return Add(a_q);
	}

	Quaternion Quaternion::operator-(const Quaternion &a_q) const {
		return Substract(a_q);
	}

	Quaternion Quaternion::operator*(const float &a_a) const {
		return Product(a_a);
	}

	Quaternion Quaternion::operator*(const Quaternion &a_q) const {
		return Product(a_q);
	}

	void Quaternion::operator+=(const Quaternion &a_v) {
		*this = Add(a_v);
	}

	void Quaternion::operator*=(const float &a_a) {
		*this = Product(a_a);
	}

	void Quaternion::operator*=(const Quaternion &a_v) {
		*this = Product(a_v);
	}

	void Quaternion::operator-=(const Quaternion &a_v) {
		*this = Substract(a_v);
	}

	bool Quaternion::operator==(const Quaternion &a_q) const {
		return x == a_q.x && y == a_q.y && z == a_q.z && w == a_q.w;
	}

	bool Quaternion::operator!=(const Quaternion &a_q) const {
		return !(x == a_q.x && y == a_q.y && z == a_q.z && w == a_q.w);
	}

	Quaternion Quaternion::Identity = Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
	Quaternion Quaternion::Zero = Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
	Quaternion Quaternion::One = Quaternion(1.0f, 0.0f, 0.0f, 0.0f);
}
