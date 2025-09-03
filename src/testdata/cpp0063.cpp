#include <iostream>
#include <cstdlib>

// BAD: Null pointer dereference (violation)
void bad_example() {
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 42;  // Potential null pointer dereference
    std::cout << "BAD example: ptr = " << *ptr << std::endl;
    free(ptr);
}

// GOOD: Check pointer before dereferencing
void good_example() {
    int* ptr = (int*)malloc(sizeof(int));
    if (ptr != nullptr) {  // Validate pointer
        *ptr = 42;
        std::cout << "GOOD example: ptr = " << *ptr << std::endl;
    } else {
        std::cerr << "GOOD example: malloc failed" << std::endl;
    }
    free(ptr);
}

int main() {
    bad_example();
    good_example();

    return 0;
}
