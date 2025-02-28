# include additional CMake functions.
include(FetchContent)

# Clone assimp repository at master and output in SOURCE_DIR location.
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.16.0
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Equivalent to add_subdirectory() for fetch content.
FetchContent_MakeAvailable(googletest)