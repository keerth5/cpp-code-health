#include <iostream>

// BAD: Multiple statements on a single line (violation)
void bad_example() {
    int x = 1; int y = 2; int z = 3;
    std::cout << "BAD example: x=" << x << ", y=" << y << ", z=" << z << std::endl;
}

// GOOD: One statement per line
void good_example() {
    int x = 1;
    int y = 2;
    int z = 3;
    std::cout << "GOOD example: x=" << x << ", y=" << y << ", z=" << z << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
