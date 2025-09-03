#include <iostream>

// BAD: Function with >50 lines (violation)
void bad_example() {
    std::cout << "BAD example start" << std::endl;
    for (int i = 0; i < 55; ++i) { // Simulate 55 lines of work
        std::cout << "Line " << i + 1 << std::endl;
    }
    std::cout << "BAD example end" << std::endl;
}

// GOOD: Break large function into smaller functions
void helper_function(int line) {
    std::cout << "Line " << line << std::endl;
}

void good_example() {
    std::cout << "\nGOOD example start" << std::endl;
    for (int i = 0; i < 55; ++i) {
        helper_function(i + 1);
    }
    std::cout << "GOOD example end" << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
