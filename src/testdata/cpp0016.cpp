#include <iostream>

// BAD: Allocating memory with 'new' but never freeing it (resource leak)
void bad_example() {
    int* ptr = new int(5);
    std::cout << "Bad Example Value: " << *ptr << std::endl;
    // Memory leak: 'delete ptr;' is missing
}

// GOOD: Proper allocation and deallocation
void good_example() {
    int* ptr = new int(10);
    std::cout << "Good Example Value: " << *ptr << std::endl;
    delete ptr; // Freed properly
}

int main() {
    std::cout << "Running bad example...\n";
    bad_example();

    std::cout << "Running good example...\n";
    good_example();

    return 0;
}
