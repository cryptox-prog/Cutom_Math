@echo off
if not exist build mkdir build
gcc -c src/main.c -I./src/lib/customMath -o build/main.o
gcc -c src/lib/customMath/exponents/exponents.c -I./src/lib/customMath -o build/exponents.o
gcc -c src/lib/customMath/trigonometery/trigonometric.c -I./src/lib/customMath -o build/trigonometric.o
gcc -c src/lib/customMath/utilities/math_utils.c -I./src/lib/customMath -o build/math_utils.o
gcc -c src/lib/customMath/array_handling/sorter.c -I/src/lib/customMath -o build/sorter.o
gcc -c src/lib/customMath/vectors/vector.c -I/src/lib/customMath -o build/vector.o
gcc -o build/main build/main.o build/exponents.o build/trigonometric.o build/math_utils.o build/sorter.o build/vector.o
echo Build complete!

