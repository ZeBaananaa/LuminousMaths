#include "Quaternion.h"
#include "Vector3.hpp"
#include <iostream>


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
		return Quaternion(x+a_q.x, y + a_q.y, z + a_q.z, w + a_q.w);
	}

	Quaternion Quaternion::Substract(const Quaternion& a_q) const
	{
		return Quaternion(x - a_q.x, y - a_q.y, z - a_q.z, w - a_q.w);
	}

	 Quaternion Quaternion::Product(const Quaternion& a_q) const
	{
		return Quaternion
		(
			
			
			w* a_q.x + x * a_q.w + y * a_q.z - z * a_q.y,
			w* a_q.y - x * a_q.z + y * a_q.w + z * a_q.x,
			w* a_q.z + x * a_q.y - y * a_q.x + z * a_q.w,
			w* a_q.w - x * a_q.x - y * a_q.y - z * a_q.z

		);
	}


	void Quaternion::Print() const
	{
		std::cout << w << ", " << x << ", " << y << ", " << z << '\n';
	}

}
