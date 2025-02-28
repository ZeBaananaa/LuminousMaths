# Create an executable based on the main.cpp
add_executable(L_MATHS_UT "main.cpp" "Test.cpp")

# Link GTest & GLM to the L_MATHS_UT Library
target_link_libraries(L_MATHS_UT PRIVATE L_MATHS GTest::gtest_main glm::glm)

# Register the test with the name L_MATHS_CTEST & Make it run the L_MATHS_UT executable
add_test(NAME L_MATHS_CTEST COMMAND L_MATHS_UT)