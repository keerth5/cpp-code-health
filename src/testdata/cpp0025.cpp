#include <iostream>

// BAD: Deeply nested if statements (violation)
void bad_example(int a, int b, int c, int d) {
    if (a > 0) {
        if (b > 0) {
            if (c > 0) {
                if (d > 0) {
                    std::cout << "BAD example: all values positive" << std::endl;
                }
            }
        }
    }
}

// GOOD: Use early returns or guard clauses to reduce nesting
void good_example(int a, int b, int c, int d) {
    if (a <= 0) return;
    if (b <= 0) return;
    if (c <= 0) return;
    if (d <= 0) return;

    std::cout << "GOOD example: all values positive" << std::endl;
}

int main() {
    int a = 1, b = 2, c = 3, d = 4;

    bad_example(a, b, c, d);  // Deeply nested
    good_example(a, b, c, d); // Flattened with guard clauses

    return 0;
}
