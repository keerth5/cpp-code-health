#include <iostream>

void bad_example() {
    // BAD: Uninitialized variable (violation)
    int x; // Declared but not initialized
    std::cout << "Bad example, uninitialized x = " << x << std::endl; // Undefined behavior
}

void good_example() {
    // GOOD: Properly initialized variable
    int x = 0; 
    std::cout << "Good example, initialized x = " << x << std::endl;
}

int main() {
    bad_example();
    good_example();
    return 0;
}
