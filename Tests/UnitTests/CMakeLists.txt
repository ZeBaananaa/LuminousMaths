add_executable(L_MATHS_UT "main.cpp")

target_link_libraries(L_MATHS_UT PRIVATE L_MATHS GTest::gtest_main)
target_link_libraries(L_MATHS_UT PRIVATE L_MATHS glm::glm)

add_test(NAME L_MATHS_CTEST COMMAND L_MATHS_UT)