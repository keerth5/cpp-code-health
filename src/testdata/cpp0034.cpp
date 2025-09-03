#include <iostream>
#include <cstdio>

// BAD: Using scanf without field width (violation)
void bad_example() {
    char buffer[100];
    std::cout << "BAD example: Enter a string: ";
    // Unsafe: no limit, can cause buffer overflow
    scanf("%s", buffer);
    std::cout << "You entered: " << buffer << std::endl;
}

// GOOD: Using scanf with field width specifier
void good_example() {
    char buffer[100];
    std::cout << "\nGOOD example: Enter a string: ";
    // Safe: limit input to buffer size - 1
    scanf("%99s", buffer);
    std::cout << "You entered: " << buffer << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
