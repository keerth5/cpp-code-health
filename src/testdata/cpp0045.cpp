#include <iostream>

// BAD: Missing blank line after variable declarations (violation)
void bad_example() {
    int x = 5;
    float y = 3.14;
    std::cout << "BAD example: x=" << x << ", y=" << y << std::endl;
    std::cout << "Continuing code without blank line" << std::endl;
}

// GOOD: Add a blank line after variable declarations
void good_example() {
    int x = 5;
    float y = 3.14;

    std::cout << "GOOD example: x=" << x << ", y=" << y << std::endl;
    std::cout << "Code separated by blank line for readability" << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
