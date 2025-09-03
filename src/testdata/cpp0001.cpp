#include <iostream>
#include <cstring>

int main() {
    char src[] = "Hello, World!";
    char dest[10];

    // BAD: Unsafe strcpy (violation)
    strcpy(dest, src); // This can cause buffer overflow

    std::cout << "Dest contains: " << dest << std::endl;

    // GOOD: Safe strncpy
    strncpy(dest, src, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0'; // Ensure null termination

    std::cout << "Dest safely contains: " << dest << std::endl;

    // GOOD: Using strcpy_s (if supported, e.g., MSVC)
#ifdef _MSC_VER
    strcpy_s(dest, sizeof(dest), src);
    std::cout << "Dest safely with strcpy_s: " << dest << std::endl;
#endif

    return 0;
}
