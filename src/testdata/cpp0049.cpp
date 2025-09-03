#include <iostream>

// BAD: Commented out code blocks (violation)
void bad_example() {
    // int x = 5;
    // float y = 3.14;
    // void func() { std::cout << "Hello"; }
    // for (int i = 0; i < 10; i++) { std::cout << i; }

    std::cout << "BAD example: commented out code blocks present" << std::endl;
}

// GOOD: Remove commented out code, keep only meaningful comments
void good_example() {
    int x = 5;
    float y = 3.14;

    // Initialize variables and display values
    std::cout << "GOOD example: x=" << x << ", y=" << y << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
