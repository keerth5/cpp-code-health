#include <iostream>
#include <cstdlib>  // for malloc/free

// BAD: Using alloca() (violation)
void bad_example(size_t size) {
    char* buffer = (char*)alloca(size); // stack allocation, risk of overflow
    for (size_t i = 0; i < size; i++) {
        buffer[i] = 'A';
    }
    buffer[size - 1] = '\0';

    std::cout << "BAD example: buffer created with alloca: " << buffer << std::endl;
}

// GOOD: Use malloc/free for dynamic allocation
void good_example(size_t size) {
    char* buffer = (char*)malloc(size); // heap allocation
    if (buffer == nullptr) {
        std::cerr << "Memory allocation failed" << std::endl;
        return;
    }
    for (size_t i = 0; i < size; i++) {
        buffer[i] = 'A';
    }
    buffer[size - 1] = '\0';

    std::cout << "GOOD example: buffer created with malloc: " << buffer << std::endl;

    free(buffer); // release memory
}

int main() {
    bad_example(10);
    good_example(10);

    return 0;
}
