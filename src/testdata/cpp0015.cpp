#include <iostream>

// BAD: Parameter is a non-const pointer (violation)
void bad_func(char* str) {
    // Function does not modify str, but parameter isn’t const
    std::cout << "Bad function received: " << str << std::endl;
}

// GOOD: Parameter marked const since function does not modify it
void good_func(const char* str) {
    std::cout << "Good function received: " << str << std::endl;
}

// BAD: Reference parameter missing const (violation)
void bad_ref(std::string& name) {
    std::cout << "Hello, " << name << std::endl;
}

// GOOD: Reference parameter marked const
void good_ref(const std::string& name) {
    std::cout << "Hello, " << name << std::endl;
}

int main() {
    char text[] = "World";
    std::string user = "Alice";

    // Call bad and good functions
    bad_func(text);    // Violation
    good_func(text);   // Compliant

    bad_ref(user);     // Violation
    good_ref(user);    // Compliant

    return 0;
}
