#include <iostream>

// BAD: Pointer arithmetic without bounds check (violation)
void bad_example() {
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    int offset = 7; // unsafe offset

    // No bounds check — may write past array
    *(ptr + offset) = 42;

    std::cout << "BAD example: arr[7] set to 42 (undefined behavior)" << std::endl;
}

// GOOD: Pointer arithmetic with bounds check
void good_example() {
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    int offset = 3;
    int* end_ptr = arr + sizeof(arr)/sizeof(arr[0]);

    if ((ptr + offset) < end_ptr) {
        *(ptr + offset) = 42;
        std::cout << "GOOD example: arr[" << offset << "] safely set to 42" << std::endl;
    } else {
        std::cerr << "GOOD example: offset out of bounds" << std::endl;
    }
}

int main() {
    bad_example();   // Vulnerable
    good_example();  // Safe

    return 0;
}
