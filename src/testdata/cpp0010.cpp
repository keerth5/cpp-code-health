#include <iostream>
#include <cstdlib>

void bad_example() {
    // BAD: malloc without free (violation)
    char* ptr = (char*)malloc(100);
    if (!ptr) return;
    // Forgot to call free(ptr); -> Memory leak
    std::cout << "Bad example: allocated memory but not freed" << std::endl;
}

void good_example() {
    // GOOD: malloc with proper free
    char* ptr = (char*)malloc(100);
    if (!ptr) return;

    // Use the allocated memory
    snprintf(ptr, 100, "Hello, World!");
    std::cout << "Good example: " << ptr << std::endl;

    // Properly free memory
    free(ptr);
}

int main() {
    bad_example();
    good_example();
    return 0;
}
