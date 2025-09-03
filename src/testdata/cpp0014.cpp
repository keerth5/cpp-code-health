#include <iostream>
#include <cstdio>
#include <cstring>

void bad_example() {
    char buffer[10];
    int value = 12345;

    // BAD: Using sprintf without bounds (violation)
    sprintf(buffer, "Value: %d", value); // Potential buffer overflow
    std::cout << "Bad example buffer: " << buffer << std::endl;
}

void good_example() {
    char buffer[10];
    int value = 12345;

    // GOOD: Using snprintf with size limit
    snprintf(buffer, sizeof(buffer), "Value: %d", value);
    std::cout << "Good example buffer: " << buffer << std::endl;
}

int main() {
    // ⚠️ Commented out bad_example() to avoid unsafe behavior
    // bad_example();

    good_example();
    return 0;
}
