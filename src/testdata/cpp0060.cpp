#include <iostream>

// BAD: Unsigned integer underflow (violation)
void bad_example() {
    unsigned int x = 0;
    x = x - 1;  // Underflow: wraps around to UINT_MAX
    std::cout << "BAD example: x = " << x << std::endl;
}

// GOOD: Check bounds before subtraction
void good_example() {
    unsigned int x = 0;
    if (x > 0) {
        x = x - 1;  // Safe subtraction
    }
    std::cout << "GOOD example: x = " << x << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
