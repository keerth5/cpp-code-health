#include <iostream>
#include <cstdio>
#include <string>

// BAD: Using user-controlled format string (violation)
void bad_example(const std::string& user_format, const char* name) {
    char buffer[128];
    // Dangerous: user controls the format string
    sprintf(buffer, user_format.c_str(), name);
    std::cout << "BAD example: buffer = " << buffer << std::endl;
}

// GOOD: Use fixed format string and pass user data as argument
void good_example(const std::string& user_input) {
    char buffer[128];
    // Safe: fixed format string, user input is treated as data
    snprintf(buffer, sizeof(buffer), "Hello, %s!", user_input.c_str());
    std::cout << "GOOD example: buffer = " << buffer << std::endl;
}

int main() {
    std::string unsafe_format = "%s %s"; // User-controlled format (BAD)
    const char* name = "Alice";

    bad_example(unsafe_format, name); // Vulnerable

    std::string safe_input = "Bob";
    good_example(safe_input); // Safe

    return 0;
}
