#include <iostream>
#include <vector>

// BAD: Using user input directly as array index (violation)
void bad_example(int user_index) {
    int arr[5] = {0, 1, 2, 3, 4};

    // No bounds check — can cause out-of-bounds access
    arr[user_index] = 42;

    std::cout << "BAD example: arr[" << user_index << "] set to 42" << std::endl;
}

// GOOD: Validate user input before accessing array
void good_example(int user_index) {
    int arr[5] = {0, 1, 2, 3, 4};

    if (user_index >= 0 && user_index < 5) {
        arr[user_index] = 42;
        std::cout << "GOOD example: arr[" << user_index << "] safely set to 42" << std::endl;
    } else {
        std::cerr << "GOOD example: invalid index " << user_index << std::endl;
    }
}

int main() {
    int user_index_bad = 7;   // Unsafe index
    int user_index_good = 3;  // Safe index

    bad_example(user_index_bad);   // Vulnerable
    good_example(user_index_good); // Safe

    return 0;
}
