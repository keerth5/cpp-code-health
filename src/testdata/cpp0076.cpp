#include <iostream>
#include <cstdlib>
#include <cstdio>

// BAD: Missing error handling for malloc and fopen (violation)
void bad_example() {
    size_t size = 1024;
    char* buffer = (char*)malloc(size); // No check for NULL
    buffer[0] = 'A'; // Potential crash if malloc failed

    FILE* file = fopen("nonexistent.txt", "r"); // No check for NULL
    char c = fgetc(file); // Undefined behavior if fopen failed

    std::cout << "BAD example executed (may crash)" << std::endl;

    free(buffer);
    fclose(file); // May also crash if file is NULL
}

// GOOD: Proper error handling for malloc and fopen
void good_example() {
    size_t size = 1024;
    char* buffer = (char*)malloc(size);
    if (!buffer) {
        std::cerr << "GOOD example: malloc failed" << std::endl;
        return;
    }

    FILE* file = fopen("nonexistent.txt", "r");
    if (!file) {
        std::cerr << "GOOD example: fopen failed" << std::endl;
        free(buffer);
        return;
    }

    buffer[0] = 'A';
    char c = fgetc(file);
    std::cout << "GOOD example executed safely, first char: " << c << std::endl;

    free(buffer);
    fclose(file);
}

int main() {
    bad_example();   // Vulnerable
    good_example();  // Safe

    return 0;
}
