#include <iostream>
#include <cstdlib>

// BAD: Large local array causing stack overflow (violation)
void bad_example() {
    // Allocating 100,000 integers on the stack
    int huge_array[100000]; // May cause stack overflow

    for (int i = 0; i < 100000; ++i) {
        huge_array[i] = i;
    }

    std::cout << "BAD example: huge_array[0] = " << huge_array[0] << std::endl;
}

// GOOD: Use dynamic allocation (heap) to avoid stack overflow
void good_example() {
    size_t size = 100000;
    int* heap_array = new int[size]; // Allocated on heap

    for (size_t i = 0; i < size; ++i) {
        heap_array[i] = i;
    }

    std::cout << "GOOD example: heap_array[0] = " << heap_array[0] << std::endl;
    delete[] heap_array; // Free heap memory
}

int main() {
    // bad_example(); // Unsafe — may crash
    good_example(); // Safe

    return 0;
}
