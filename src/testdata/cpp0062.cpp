#include <iostream>
#include <cstring>

// BAD: Using banned strcpy variants without bounds checking
void bad_example() {
    char dest[16];
    const char* src = "ThisIsAVeryLongSourceString";

    strcpy(dest, src); // Unsafe: may overflow dest
    std::cout << "BAD example: dest = " << dest << std::endl;
}

// GOOD: Use safe alternatives with bounds checking
void good_example() {
    char dest[16];
    const char* src = "ThisIsAVeryLongSourceString";

    // Use strncpy with size limit
    strncpy(dest, src, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0'; // Ensure null termination

    std::cout << "GOOD example: dest = " << dest << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
