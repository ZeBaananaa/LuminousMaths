#include "pch.h"
#include "Matrix3.h"

Math::Matrix3::Matrix3(float a_a)
{
	for(int i = 0; i < 3; ++i)
	{
		for (int y = 0; y < 3; ++y)
		{
			mat[i][y] = a_a;
		}
	}
}

Math::Matrix3::Matrix3(const float(&a_mat)[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int y = 0; y < 3; ++y)
		{
			mat[i][y] = a_mat[i][y];
		}
	}
}

Math::Matrix3::Matrix3(Vector3 a_v[3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int y = 0; y < 3; ++y)
		{
			mat[i][y] = a_v[i][y];
		}
	}
}

void Math::Matrix3::Print()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int y = 0; y < 3; ++y)
		{
			std::cout << mat[i][y] << ", ";
		}
		std::cout << '\n';
	}
}
