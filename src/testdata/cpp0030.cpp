#include <iostream>

// BAD: Switch without default case (violation)
void bad_example(int value) {
    std::cout << "BAD example:" << std::endl;
    switch (value) {
        case 1:
            std::cout << "Case 1" << std::endl;
            break;
        case 2:
            std::cout << "Case 2" << std::endl;
            break;
        // Missing default case
    }
}

// GOOD: Switch with default case
void good_example(int value) {
    std::cout << "\nGOOD example:" << std::endl;
    switch (value) {
        case 1:
            std::cout << "Case 1" << std::endl;
            break;
        case 2:
            std::cout << "Case 2" << std::endl;
            break;
        default:
            std::cout << "Default case" << std::endl;
            break;
    }
}

int main() {
    int val = 3;

    bad_example(val);  // Missing default
    good_example(val); // Default handled

    return 0;
}
