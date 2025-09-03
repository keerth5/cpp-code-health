#include <iostream>
#include <cstdlib>

int main() {
    int* ptr = (int*)malloc(sizeof(int));
    if (!ptr) return 1;

    *ptr = 10;

    // BAD: Dangling pointer dereference (violation)
    free(ptr);
    *ptr = 5; // Undefined behavior: ptr points to freed memory

    std::cout << "Bad example value: " << *ptr << std::endl;

    // GOOD: Nullify pointer after free
    int* safe_ptr = (int*)malloc(sizeof(int));
    if (!safe_ptr) return 1;
    *safe_ptr = 20;

    free(safe_ptr);
    safe_ptr = nullptr; // Prevent dangling pointer

    // Safe to check before dereference
    if (safe_ptr) {
        *safe_ptr = 30;
    } else {
        std::cout << "Pointer is null, safe usage" << std::endl;
    }

    return 0;
}
