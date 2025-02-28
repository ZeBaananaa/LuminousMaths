# include additional CMake functions.
include(FetchContent)

# Check if GoogleTest target already exists
if (NOT TARGET googletest)
    # Clone googletest repository at master and output in CMAKE_CURRENT_SOURCE_DIR location.
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG v1.16.0
            SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest
    )

    # Tag is only required for visualstudio
    if (MSVC)
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    endif ()

    # Equivalent to add_subdirectory() for fetch content.
    FetchContent_MakeAvailable(googletest)

endif ()



# Check if GLM target already exists
if (NOT TARGET glm)
    FetchContent_Declare(
            glm
            GIT_REPOSITORY https://github.com/g-truc/glm.git
            GIT_TAG 1.0.1
            SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glm
    )
    # Equivalent to add_subdirectory() for fetch content.
    FetchContent_MakeAvailable(glm)
endif ()