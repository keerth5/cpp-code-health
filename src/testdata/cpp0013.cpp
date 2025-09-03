#include <iostream>

void bad_example() {
    int arr[10];

    // BAD: Out-of-bounds access (violation)
    arr[10] = 42; // Index 10 is invalid since valid indices are 0–9
    std::cout << "Bad access: " << arr[10] << std::endl;
}

void good_example() {
    int arr[10];
    int index = 9;

    // GOOD: Bounds check before access
    if (index < 10) {
        arr[index] = 42;
        std::cout << "Good access: " << arr[index] << std::endl;
    } else {
        std::cout << "Index out of bounds, safe handling" << std::endl;
    }
}

int main() {
    // ⚠️ Bad example causes undefined behavior, so it’s commented out
    // bad_example();

    good_example();
    return 0;
}
