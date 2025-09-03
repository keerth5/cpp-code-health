#include <iostream>
#include <cstdio>

int main() {
    char buffer[20];

    // BAD: Unsafe gets() usage (violation)
    std::cout << "Enter text (unsafe): ";
    gets(buffer); // Can cause buffer overflow
    std::cout << "You entered (unsafe): " << buffer << std::endl;

    // GOOD: Safe fgets usage
    std::cout << "Enter text (safe): ";
    fgets(buffer, sizeof(buffer), stdin); // Reads at most sizeof(buffer)-1 characters
    // Remove trailing newline added by fgets
    buffer[strcspn(buffer, "\n")] = '\0';
    std::cout << "You entered (safe): " << buffer << std::endl;

    return 0;
}
