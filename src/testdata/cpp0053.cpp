#include <iostream>
#include <climits>

// BAD: Signed integer overflow in loop condition (violation)
void bad_example() {
    std::cout << "BAD example: signed overflow in loop" << std::endl;
    for (int i = INT_MAX - 1; i < INT_MAX + 10; i++) {
        std::cout << i << " "; // Undefined behavior when i overflows
    }
    std::cout << std::endl;
}

// GOOD: Use unsigned or check bounds to avoid overflow
void good_example() {
    std::cout << "GOOD example: avoid signed overflow in loop" << std::endl;
    unsigned int start = static_cast<unsigned int>(INT_MAX - 1);
    unsigned int end = static_cast<unsigned int>(INT_MAX - 1 + 10);
    for (unsigned int i = start; i <= end; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
