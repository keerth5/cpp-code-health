#include <iostream>
#include <stdexcept>

// BAD: Empty catch block (violation)
void bad_example() {
    try {
        throw std::runtime_error("Something went wrong!");
    } catch (const std::exception& e) {
        // Empty catch → exception silently ignored
    }
    std::cout << "BAD example finished (exception hidden)" << std::endl;
}

// GOOD: Catch and handle or log the exception
void good_example() {
    try {
        throw std::runtime_error("Something went wrong!");
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl; // Proper handling
    }
    std::cout << "GOOD example finished" << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
