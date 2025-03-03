#include "pch.h"
#include "Vectors.h"
#include "Utils.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include <iostream>


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

int main()
{
	Math::Vector2 v = Math::Vector2(5.0f, 4.0f);
	Math::Vector2 v2 = Math::Vector2(15.0f, 8.0f);

	Math::Vector2 v3 = Math::Vector2::zero;

	//v2 = v2.Normalize();

	Math::Vector3 v3d = Math::Vector3(5.0f, 6.0f, 3.0f);
	Math::Vector3 v3d2 = Math::Vector3(2.0f, 8.0f, 14.0f);
	Math::Vector3 v3d3 = Math::Vector3(2.0f, 8.0f, 14.0f);


	Math::Vector3 a[3] = { v3d,v3d2,v3d3 };
	//Math::Matrix3 m3 = Math::Matrix3({ {1,1,1} ,{1,1,1} ,{1,1,1}});
	//Math::Matrix3 m3 = Math::Matrix3(v3d,v3d2 ,v3d3);
	//Math::Matrix3 m32 = Math::Matrix3({{1.0f,8.0f,3.0f},{4.0f,1.0f,24.0f},{7.0f,2.0f,12.0f}});


	Math::Matrix4 m3 = Math::Matrix4({ {1.0f,1.0f,8.0f,4.0f},{21.0f,1.0f,4.0f,8.0f},{1.5f,4.0f,1.0f,5.5f},{7.0f,3.2f,4.2f,1.0f} });
	Math::Matrix4 m32 = Math::Matrix4({ {1.0f,8.0f,3.0f,5.0f},{4.0f,1.0f,24.0f,7.0f},{7.0f,2.0f,12.0f,41.0f},{4.0f,5.0f,23.0f,9.0f} });
	
	Math::Matrix4 TRS = Math::Matrix4::TRS(Math::Vector3(5, 2, 6), Math::Vector3(1, 31, 90), Math::Vector3(2, 2, 2));
	
	TRS.Print();
	/*
	(m3+m32).Print();
	(m3 - m32).Print();
	(m3 * m32).Print();
	(m3 / m32).Print();

	(m3.Transpose()).Print();
	//(m3.Inverse()).Print();
	Math::Matrix4 m = Math::Matrix4::identity;
	std::cout << m.IsOrthogonal() << '\n';
	
	if (m3 == m32) 
	{
		std::cout << "EQUALLLLL" << '\n';
	}else
	{
		std::cout << "NOT EQUALLLLL" << '\n';
	}

	//std::cout << v.CrossProduct(v2) << '\n';*/

	return 0;
}