#include <iostream>
#include <cstring>

int main() {
    char dest[20] = "Hello";
    const char* src = "World!";

    // BAD: Unsafe strcat usage (violation)
    strcat(dest, src); // Can overflow if src doesn't fit in dest
    std::cout << "Bad concat result: " << dest << std::endl;

    // Reset dest for safe example
    strcpy(dest, "Hello");

    // GOOD: Safe strncat usage with bounds checking
    strncat(dest, src, sizeof(dest) - strlen(dest) - 1);
    std::cout << "Safe concat result: " << dest << std::endl;

#ifdef _MSC_VER
    // GOOD (Windows/MSVC only): strcat_s
    strcpy(dest, "Hello");
    strcat_s(dest, sizeof(dest), src);
    std::cout << "Safe concat result with strcat_s: " << dest << std::endl;
#endif

    return 0;
}
