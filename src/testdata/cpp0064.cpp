#include <iostream>

const int ARR_SIZE = 5;

// BAD: Array bounds write overflow (violation)
void bad_example() {
    int arr[ARR_SIZE] = {0};
    int i = 10; // Out-of-bounds index
    arr[i] = 42;  // Writes outside array bounds
    std::cout << "BAD example: arr[" << i << "] = " << arr[i] << std::endl;
}

// GOOD: Check bounds before writing
void good_example() {
    int arr[ARR_SIZE] = {0};
    int i = 3; // Within bounds

    if (i < ARR_SIZE) {  // Validate index
        arr[i] = 42;
        std::cout << "GOOD example: arr[" << i << "] = " << arr[i] << std::endl;
    } else {
        std::cerr << "GOOD example: index out of bounds" << std::endl;
    }
}

int main() {
    bad_example();
    good_example();

    return 0;
}
