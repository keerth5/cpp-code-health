#include <iostream>

// BAD: Read-only variables not declared const (violation)
void bad_example() {
    int x = 5;      // never modified
    float pi = 3.14; // never modified

    std::cout << "BAD example: x=" << x << ", pi=" << pi << std::endl;
}

// GOOD: Declare read-only variables as const
void good_example() {
    const int x = 5;       // read-only
    const float pi = 3.14; // read-only

    std::cout << "GOOD example: x=" << x << ", pi=" << pi << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
