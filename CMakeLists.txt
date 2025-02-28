# --------------------------------------- #
#               CMAKE CONFIG              #
# --------------------------------------- #

# Define minimum CMake version required
cmake_minimum_required(VERSION 3.30)

# Define Project Name
project(LuminousMaths
        VERSION 1.0.0
        LANGUAGES CXX)

set(LM_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/Builds/${CMAKE_CXX_COMPILER_ID}_$<CONFIG>")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${LM_OUTPUT_DIR}/libs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${LM_OUTPUT_DIR}/libs")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${LM_OUTPUT_DIR}")

file(GLOB_RECURSE LM_SOURCES "Code/Source/*.cpp")

add_library(L_MATHS STATIC ${LM_SOURCES})

# Add Include Directory
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

enable_testing()

if (L_MATHS_UNITTEST)
    add_subdirectory(Tests)
endif()