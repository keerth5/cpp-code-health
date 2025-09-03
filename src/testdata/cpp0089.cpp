#include <iostream>
#include <stdexcept>

// BAD: Memory allocated but not properly freed on exception
void bad_example() {
    int* ptr = new int(42);
    try {
        // Function that may throw
        throw std::runtime_error("Something went wrong");
        delete ptr; // This line will never be reached
    } catch (const std::exception& e) {
        std::cout << "BAD example caught: " << e.what() << std::endl;
        // Memory leak occurs here because delete was skipped
    }
}

// GOOD: Use RAII to ensure proper cleanup
class IntWrapper {
public:
    IntWrapper(int value) : ptr(new int(value)) {}
    ~IntWrapper() { delete ptr; }
    int get() const { return *ptr; }

private:
    int* ptr;
};

void good_example() {
    try {
        IntWrapper wrapper(42); // Memory automatically cleaned up
        throw std::runtime_error("Something went wrong");
        // No explicit delete needed
    } catch (const std::exception& e) {
        std::cout << "GOOD example caught: " << e.what() << std::endl;
    }
}

int main() {
    bad_example();   // Unsafe, memory leak
    good_example();  // Safe, RAII ensures cleanup
    return 0;
}
