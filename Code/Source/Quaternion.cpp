#include "Quaternion.hpp"
#include "Vector3.hpp"
#include <iostream>
#include "Utils.hpp"


namespace Maths
{
	Quaternion::Quaternion(float a_x, float a_y, float a_z, float a_w)
	{
		w = a_w;
		x = a_x;
		y = a_y;
		z = a_z;
	}

	Quaternion::Quaternion(Vector3 a_v)
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

	Quaternion Quaternion::Substract(const Quaternion& a_q) const
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
		return Maths::Sqrt((x * x) + (y * y) + (z * z) + (w * w));
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

	Vector3 Quaternion::ToEulerAngles() const
	{
		/*
		Vector3 t_r;

		if ((w * y - z * x) > 0.5f) {
			t_r.y = Maths::m_PI * 0.5f;
			t_r.x = 2.f * atan2f(x, w);
			t_r.z = 0.f;
		}
		else if ((w * y - z * x) < -0.5f)
		{
			t_r.y = -Maths::m_PI * 0.5f;
			t_r.x = -2.f * atan2f(x, w);
			t_r.z = 0.f;
		}
		else
		{
			t_r.y = asinf(2.f * (w * y - z * x));
			t_r.x = atan2f(x * z - w * y, w * w + x * x - y * y - z * z);
			t_r.z = atan2f(y * z - w * x, w * w - x * x + y * y - z * z);
		}

		
		return Vector3(Maths::RadToDeg(t_r.x), Maths::RadToDeg(t_r.y), Maths::RadToDeg(t_r.z));*/
		return Vector3();
	}


	void Quaternion::Print() const
	{
		std::cout << w << ", " << x << ", " << y << ", " << z << '\n';
	}

	Quaternion Quaternion::FromEulerAngles(const Vector3& a_v)
	{

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
			t_cr* t_cp* t_cy + t_sr * t_sp * t_sy
		);

		return t_q;
	}

	Quaternion Quaternion::Slerp(const Quaternion& a_q1, const Quaternion& a_q2, float a_t)
	{
		return Quaternion(a_q1.x, a_q2.x, a_t, 0);
	}

	Quaternion Quaternion::operator+(const Quaternion& a_q) const
	{
		return Add(a_q);
	}

	Quaternion Quaternion::operator-(const Quaternion& a_q) const
	{
		return Substract(a_q);
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
		*this = Substract(a_v);
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