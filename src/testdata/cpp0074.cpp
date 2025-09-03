#include <iostream>
#include <cstring>

// BAD: memcpy without bounds check (violation)
void bad_example() {
    char src[10] = "123456789";
    char dest[5];

    // No check: copying 10 bytes into 5-byte buffer — buffer overflow!
    memcpy(dest, src, sizeof(src));
    std::cout << "BAD example: dest = " << dest << std::endl;
}

// GOOD: memcpy with proper bounds check
void good_example() {
    char src[10] = "123456789";
    char dest[5];

    size_t dest_size = sizeof(dest);
    size_t copy_len = sizeof(src);

    // Ensure we do not exceed dest buffer
    if (copy_len > dest_size) {
        copy_len = dest_size - 1; // leave space for null terminator
    }
    memcpy(dest, src, copy_len);
    dest[copy_len] = '\0'; // null terminate

    std::cout << "GOOD example: dest = " << dest << std::endl;
}

int main() {
    bad_example();   // Vulnerable
    good_example();  // Safe

    return 0;
}
