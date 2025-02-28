# include additional CMake functions.
include(FetchContent)

# Clone googletest repository at master and output in SOURCE_DIR location.
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.16.0
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest
)

FetchContent_Declare(
        glm
        GIT_REPOSITORY	https://github.com/g-truc/glm.git
        GIT_TAG bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glm
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Equivalent to add_subdirectory() for fetch content.
FetchContent_MakeAvailable(googletest)
FetchContent_MakeAvailable(glm)