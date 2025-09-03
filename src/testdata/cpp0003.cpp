#include <iostream>
#include <cstdio>

int main() {
    const char* user_input = "Hello, World!";

    // BAD: Unsafe printf usage (violation)
    printf(user_input); // Format string vulnerability if user_input contains format specifiers

    // GOOD: Safe printf usage
    printf("%s", user_input); // User input treated as string, no format string vulnerability

    // Additional safe example with formatting
    int num = 42;
    printf("Number is %d\n", num); // Safe usage

    return 0;
}
