#include <iostream>

// BAD: Function parameter is unused (violation)
void bad_example(int unused_param) {
    std::cout << "BAD example: function called" << std::endl;
    // unused_param is never used
}

// GOOD: Mark unused parameter with comment or omit name
void good_example(int /*unused_param*/) {
    std::cout << "GOOD example: function called" << std::endl;
}

// Alternative GOOD: Use (void) cast to suppress unused warning
void good_example2(int unused_param) {
    (void)unused_param; // explicitly mark as unused
    std::cout << "GOOD example 2: function called" << std::endl;
}

int main() {
    bad_example(42);
    good_example(42);
    good_example2(42);

    return 0;
}
