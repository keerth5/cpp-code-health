#include <iostream>

// BAD: Missing break statements (violation)
void bad_example(int value) {
    std::cout << "BAD example:" << std::endl;
    switch (value) {
        case 1:
            std::cout << "Case 1" << std::endl;
            // Missing break → fall-through
        case 2:
            std::cout << "Case 2" << std::endl;
            // Missing break → fall-through
        default:
            std::cout << "Default case" << std::endl;
    }
}

// GOOD: Proper break statements to prevent fall-through
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
    int val = 1;

    bad_example(val);
    good_example(val);

    return 0;
}
