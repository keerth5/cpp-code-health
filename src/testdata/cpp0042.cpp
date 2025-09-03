#include <iostream>

// BAD: Single statement blocks without curly braces (violation)
void bad_example(int x) {
    if (x > 0)
        std::cout << "BAD example: x is positive" << std::endl;

    for (int i = 0; i < x; i++)
        std::cout << "BAD example: loop iteration " << i << std::endl;

    while (x > 0)
        x--;
}

// GOOD: Always use curly braces even for single statements
void good_example(int x) {
    if (x > 0) {
        std::cout << "GOOD example: x is positive" << std::endl;
    }

    for (int i = 0; i < x; i++) {
        std::cout << "GOOD example: loop iteration " << i << std::endl;
    }

    while (x > 0) {
        x--;
    }
}

int main() {
    bad_example(3);
    good_example(3);

    return 0;
}
