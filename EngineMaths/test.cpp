#include "pch.h"
#include "Vector2.h"
#include "Utils.h"

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
	(v2+5.0f).Print();

	//std::cout << v.CrossProduct(v2) << '\n';

	return 0;
}