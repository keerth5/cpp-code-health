#include <iostream>
#include <cstdlib> // for system
#include <cstdio>

// BAD: Using system() with raw command (violation)
void bad_example() {
    std::cout << "BAD example:" << std::endl;

    const char* filename = "temp.txt";
    // Unsafe: user input or variable could lead to command injection
    std::string cmd = "rm " + std::string(filename);
    system(cmd.c_str());

    std::cout << "Executed system command: " << cmd << std::endl;
}

// GOOD: Avoid system(), use specific library calls
void good_example() {
    std::cout << "\nGOOD example:" << std::endl;

    const char* filename = "temp.txt";
    // Safe: use standard library file operations
    if (std::remove(filename) == 0) {
        std::cout << "File deleted successfully" << std::endl;
    } else {
        std::perror("Error deleting file");
    }
}

int main() {
    bad_example();
    good_example();

    return 0;
}
