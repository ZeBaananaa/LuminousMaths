#pragma once
#include "Vectors.h"

namespace Math
{
	class Matrix3
	{
	public:

		float mat[3][3];

		Matrix3() = default;
		Matrix3(float a_a);
		Matrix3(const float (& a_mat)[3][3]);
		Matrix3(Vector3 a_v[3]);

		void Print();

	};

}

