#include <iostream>
#include <cstring>

// BAD: strncpy without null termination (violation)
void bad_example() {
    char dest[8];
    const char* src = "ThisIsTooLong";

    // Potential overflow: dest may not be null-terminated
    strncpy(dest, src, sizeof(dest));  
    // dest may not have '\0' at the end
    std::cout << "BAD example: dest = " << dest << std::endl;
}

// GOOD: Proper null termination after strncpy
void good_example() {
    char dest[8];
    const char* src = "ThisIsTooLong";

    // Copy with size-1 to leave space for null terminator
    strncpy(dest, src, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';  // Ensure null termination

    std::cout << "GOOD example: dest = " << dest << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
