#include <iostream>
#include <cstring>
#include <cstdint>

// BAD: Pointer casting without considering alignment (violation)
void bad_example() {
    char buffer[8];
    int* int_ptr = (int*)buffer; // May cause undefined behavior on misaligned memory

    *int_ptr = 42; // Potential crash on architectures that require aligned access
    std::cout << "BAD example: value = " << *int_ptr << std::endl;
}

// GOOD: Proper alignment using memcpy or aligned storage
void good_example() {
    alignas(int) char buffer[8]; // Ensure buffer is properly aligned
    int value = 42;
    std::memcpy(buffer, &value, sizeof(int)); // Safe copy respecting alignment

    int retrieved;
    std::memcpy(&retrieved, buffer, sizeof(int));
    std::cout << "GOOD example: value = " << retrieved << std::endl;
}

int main() {
    bad_example();  // Unsafe casting
    good_example(); // Safe memory alignment handling

    return 0;
}
