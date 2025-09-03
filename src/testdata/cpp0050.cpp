#include <iostream>

// BAD: Missing function documentation (violation)
void bad_example() {
    std::cout << "BAD example: no function documentation" << std::endl;
}

/**
 * GOOD: Function with proper documentation
 * Prints a message indicating a good example.
 */
void good_example() {
    std::cout << "GOOD example: function has documentation" << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
