#include <iostream>

// BAD: Recursive function without termination condition (violation)
void bad_example() {
    std::cout << "BAD example: recursion starts" << std::endl;

    // Infinite recursion — no termination condition
    auto func = []() {
        func(); // Will cause stack overflow
    };

    // Uncommenting below line will crash the program
    // func();
}

// GOOD: Recursive function with proper termination condition
void good_example(int depth) {
    if (depth <= 0) {
        std::cout << "GOOD example: reached base case, stopping recursion" << std::endl;
        return;
    }

    std::cout << "GOOD example: depth = " << depth << std::endl;
    good_example(depth - 1); // Recursive call with decreasing depth
}

int main() {
    // bad_example(); // Unsafe — will cause stack overflow
    good_example(5); // Safe recursion

    return 0;
}
