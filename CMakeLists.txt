# --------------------------------------- #
#               CMAKE CONFIG              #
# --------------------------------------- #

# Define minimum CMake version required
cmake_minimum_required(VERSION 3.20)

# Define Project Name
project(LuminousMaths
        VERSION 1.0.0
        LANGUAGES CXX)

# Define output build folder
set(LM_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/Builds/${CMAKE_CXX_COMPILER_ID}_$<CONFIG>")

# Define Output Build path for libraries & executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${LM_OUTPUT_DIR}/libs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${LM_OUTPUT_DIR}/libs")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${LM_OUTPUT_DIR}")

# Store the sources into a variable `LM_SOURCES`
file(GLOB_RECURSE LM_SOURCES "Code/Source/*.cpp")

# Add sources to the library
add_library(L_MATHS STATIC ${LM_SOURCES} "Code/Include/Quaternion.hpp" "Code/Source/Quaternion.cpp")

# Add Include Directory to the library
target_include_directories(L_MATHS PUBLIC "Code/Include")

# Define C++ Standard Version
target_compile_features(L_MATHS PRIVATE cxx_std_20)

# Set Warning level 4 and warnings as errors flags
if (MSVC)
    target_compile_options(L_MATHS PRIVATE /W4 /WX)
else ()
    target_compile_options(L_MATHS PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif ()



# --------------------------------------- #
#             CREATE OPTIONS              #
# --------------------------------------- #

option(L_MATHS_UNITTEST "Enable Unit Tests" ON)



# --------------------------------------- #
#        Enable Testing & Sub Dirs        #
# --------------------------------------- #

# Enable CTests
enable_testing()

# Enable GoogleTest & GLM
if (L_MATHS_UNITTEST)
    add_subdirectory(Tests)
endif()