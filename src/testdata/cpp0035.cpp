#include <iostream>

// BAD: Bitwise operations on signed integers (violation)
void bad_example() {
    int x = -8;
    int y = x >> 1; // Undefined or implementation-defined behavior
    std::cout << "BAD example: x = " << x << ", x >> 1 = " << y << std::endl;

    x = -5;
    int z = x & 0x0F; // Bitwise AND on signed int
    std::cout << "BAD example: x = " << x << ", x & 0x0F = " << z << std::endl;
}

// GOOD: Use unsigned integers for bitwise operations
void good_example() {
    unsigned int x = 8;
    unsigned int y = x >> 1; // Well-defined
    std::cout << "\nGOOD example: x = " << x << ", x >> 1 = " << y << std::endl;

    x = 5;
    unsigned int z = x & 0x0F; // Safe
    std::cout << "GOOD example: x = " << x << ", x & 0x0F = " << z << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
