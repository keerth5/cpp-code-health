#include <iostream>

int main() {
    int* ptr = nullptr;
    int value = 42;

    // BAD: Dereferencing without null check (violation)
    *ptr = value; // Undefined behavior if ptr is NULL

    std::cout << "Bad assignment done" << std::endl;

    // GOOD: Check for null before dereference
    int* safe_ptr = new int;
    if (safe_ptr != NULL) {
        *safe_ptr = value;
        std::cout << "Good assignment: " << *safe_ptr << std::endl;
    } else {
        std::cout << "Pointer is NULL, cannot dereference safely" << std::endl;
    }

    delete safe_ptr;

    return 0;
}
