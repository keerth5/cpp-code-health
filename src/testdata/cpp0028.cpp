#include <iostream>

// BAD: Using assignment operator in condition (violation)
void bad_example() {
    int x = 0;
    std::cout << "BAD example:" << std::endl;

    if (x = 5) { // Mistaken assignment instead of comparison
        std::cout << "Inside if block, x = " << x << std::endl;
    } else {
        std::cout << "Else block" << std::endl;
    }
}

// GOOD: Using equality operator for comparison
void good_example() {
    int x = 0;
    std::cout << "\nGOOD example:" << std::endl;

    if (x == 5) { // Correct comparison
        std::cout << "Inside if block, x = " << x << std::endl;
    } else {
        std::cout << "Else block" << std::endl;
    }
}

int main() {
    bad_example();
    good_example();

    return 0;
}
