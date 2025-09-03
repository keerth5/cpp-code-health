#include <iostream>
#include <cstring>

// BAD: Critical security variable not initialized
void bad_example() {
    char password[32]; // uninitialized
    // Using the variable without initialization
    std::cout << "BAD example: password first char = " << password[0] << std::endl;
}

// GOOD: Properly initialize critical security variable
void good_example() {
    char password[32] = {0}; // initialize all bytes to 0
    std::strcpy(password, "secure_pass");
    std::cout << "GOOD example: password first char = " << password[0] << std::endl;
}

int main() {
    bad_example();   // Unsafe: may contain garbage data
    good_example();  // Safe: initialized before use

    return 0;
}
