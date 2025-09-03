#include <iostream>
#include <cstdio>
#include <cstring>

// BAD: Using sprintf without buffer size (violation)
void bad_example(const char* input) {
    char buf[16];
    sprintf(buf, "%s", input); // Risk of stack buffer overflow
    std::cout << "BAD example: buf = " << buf << std::endl;
}

// GOOD: Use snprintf with explicit buffer size
void good_example(const char* input) {
    char buf[16];
    snprintf(buf, sizeof(buf), "%s", input); // Safe
    std::cout << "GOOD example: buf = " << buf << std::endl;
}

int main() {
    const char* unsafe_input = "ThisIsAVeryLongInputString";
    const char* safe_input = "ShortInput";

    bad_example(unsafe_input);
    good_example(safe_input);

    return 0;
}
