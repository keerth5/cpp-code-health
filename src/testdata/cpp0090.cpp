#include <iostream>
#include <algorithm> // For std::min

int main() {
    const int arr_size = 5;
    int arr[arr_size] = {1, 2, 3, 4, 5};

    int user_count = 10; // Example user input

    // BAD: Loop does not check array bounds
    std::cout << "BAD example:\n";
    for (int i = 0; i < user_count; i++) {
        // Unsafe access: arr[i] may go out of bounds
        std::cout << arr[i] << " "; // Undefined behavior when i >= arr_size
    }
    std::cout << "\n";

    // GOOD: Validate array size in loop condition
    std::cout << "GOOD example:\n";
    for (int i = 0; i < std::min(user_count, arr_size); i++) {
        // Safe access within array bounds
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
