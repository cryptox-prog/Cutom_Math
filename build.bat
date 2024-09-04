@echo off
if not exist build mkdir build
gcc -c src/main.c -I./src/lib/customMath -o build/main.o
gcc -c src/lib/customMath/exponents/exponents.c -I./src/lib/customMath -o build/exponents.o
gcc -c src/lib/customMath/trigonometery/trigonometric.c -I./src/lib/customMath -o build/trigonometric.o
gcc -c src/lib/customMath/utilities/math_utils.c -I./src/lib/customMath -o build/math_utils.o
gcc -o build/main build/main.o build/exponents.o build/trigonometric.o build/math_utils.o
echo Build complete!
