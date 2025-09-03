#include <iostream>
#include <cstdlib>

int main() {
    // Allocate memory
    int* ptr = (int*)malloc(sizeof(int));
    if (!ptr) return 1;
    *ptr = 42;

    // BAD: Double free (violation)
    free(ptr);
    free(ptr); // Undefined behavior: double free

    // GOOD: Free once and nullify pointer
    int* safe_ptr = (int*)malloc(sizeof(int));
    if (!safe_ptr) return 1;
    *safe_ptr = 100;

    free(safe_ptr);
    safe_ptr = nullptr; // Prevent double free
    // Safe to call free again
    if (safe_ptr) {
        free(safe_ptr);
    } else {
        std::cout << "Pointer already freed safely" << std::endl;
    }

    return 0;
}
