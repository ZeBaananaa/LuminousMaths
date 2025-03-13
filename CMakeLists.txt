# --------------------------------------- #
#               CMAKE CONFIG              #
# --------------------------------------- #

# Define minimum CMake version required
cmake_minimum_required(VERSION 3.20)

# Define Project Name
project(LuminousMaths
        VERSION 1.0.1
        LANGUAGES CXX)

# Define output build folder
set(LM_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/Builds/${CMAKE_CXX_COMPILER_ID}_$<CONFIG>")

# Define Output Build path for libraries & executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${LM_OUTPUT_DIR}/libs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${LM_OUTPUT_DIR}/libs")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${LM_OUTPUT_DIR}")

# To build shared libraries in Windows, we set CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS to TRUE.
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Build position independent code.
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Disable C and C++ compiler extensions.
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

# Store the sources into a variable `LM_SOURCES`
file(GLOB_RECURSE LM_SOURCES "Code/Source/*.cpp")

# Define the lib name for easy modification
set(LM_LIB_NAME L_MATHS)

# Add sources to the library
add_library(${LM_LIB_NAME} SHARED ${LM_SOURCES})

# Add Include Directory to the library
target_include_directories(${LM_LIB_NAME} PUBLIC "Code/Include")

# Define the math export
target_compile_definitions(${LM_LIB_NAME} PRIVATE LUMINOUS_MATHS_EXPORTS)

# Define C++ Standard Version
target_compile_features(${LM_LIB_NAME} PRIVATE cxx_std_23)

# Disable lib prefix
set_target_properties(${LM_LIB_NAME} PROPERTIES PREFIX "")

# Set dll name
set_target_properties(${LM_LIB_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-${PROJECT_VERSION}")

# Set Warning level 4 and warnings as errors flags
if (MSVC)
    set(CMAKE_DEBUG_POSTFIX "d")
    target_compile_options(${LM_LIB_NAME} PRIVATE /W3 /WX)
else ()
    target_compile_options(${LM_LIB_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif ()



# --------------------------------------- #
#             CREATE OPTIONS              #
# --------------------------------------- #

option(${LM_LIB_NAME}_UNITTEST "Enable Unit Tests" OFF)



# --------------------------------------- #
#        Enable Testing & Sub Dirs        #
# --------------------------------------- #

# Enable CTests
enable_testing()

# Enable GoogleTest & GLM
if (${LM_LIB_NAME}_UNITTEST)
    add_subdirectory(Tests)
endif()