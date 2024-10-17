# CMakeLists.txt

# For Floating Point Comparison
add_definitions(-DUNITY_INCLUDE_DOUBLE)

# CMake version
cmake_minimum_required(VERSION 3.10)
project(CustomMathTests C)

# C standard
set(CMAKE_C_STANDARD 99)

# Include directories
include_directories(src/lib/customMath tests/unity tests/exponential)

# Source files
set(SOURCES
    src/lib/customMath/exponents/exponents.c
    src/lib/customMath/trigonometery/trigonometric.c
    src/lib/customMath/utilities/math_utils.c
    src/lib/customMath/array_handling/sorter.c
    src/lib/customMath/vectors/vector.c
    tests/unity/unity.c
    tests/exponential/e_x_test.c
    tests/test_main.c
)

# Add the executable target
add_executable(run_tests ${SOURCES})

