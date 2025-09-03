#include <iostream>
#include <stdexcept>

class BadDestructor {
public:
    ~BadDestructor() {
        // BAD: Throwing an exception inside a destructor is unsafe
        throw std::runtime_error("Destructor threw an exception!");
    }
};

class GoodDestructor {
public:
    // GOOD: Marked noexcept and does not throw
    ~GoodDestructor() noexcept {
        std::cout << "Good destructor executed safely." << std::endl;
        // No exception thrown
    }
};

int main() {
    std::cout << "Running bad example...\n";
    try {
        BadDestructor bad;  // Will cause std::terminate due to throw in destructor
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\nRunning good example...\n";
    GoodDestructor good;  // Safe

    return 0;
}
