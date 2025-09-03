#include <iostream>
#include <cstdlib>
#include <climits>

// BAD: Integer overflow in memory allocation (violation)
void bad_example(size_t count, size_t size) {
    // Potential overflow: count * size may wrap around
    char* buffer = (char*)malloc(count * size);
    if (!buffer) {
        std::cerr << "BAD example: malloc failed" << std::endl;
        return;
    }

    std::cout << "BAD example: allocated buffer of size " << count * size << std::endl;
    free(buffer);
}

// GOOD: Check for overflow before multiplication
void good_example(size_t count, size_t size) {
    if (size != 0 && count > SIZE_MAX / size) {
        std::cerr << "GOOD example: integer overflow detected, allocation aborted" << std::endl;
        return;
    }

    char* buffer = (char*)malloc(count * size);
    if (!buffer) {
        std::cerr << "GOOD example: malloc failed" << std::endl;
        return;
    }

    std::cout << "GOOD example: allocated buffer of size " << count * size << std::endl;
    free(buffer);
}

int main() {
    size_t large_count = SIZE_MAX / 2 + 1;
    size_t element_size = 4;

    bad_example(large_count, element_size);   // Unsafe
    good_example(large_count, element_size);  // Safe

    return 0;
}
