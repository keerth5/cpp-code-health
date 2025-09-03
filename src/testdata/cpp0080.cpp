#include <iostream>
#include <stdexcept>
#include <cstdlib>

// BAD: Constructor performing operations that may throw without handling
class BadClass {
    int* data;
public:
    BadClass(size_t size) {
        // Allocation may fail, no exception handling
        data = (int*)malloc(size * sizeof(int));
        if (!data) {
            // Potential crash if malloc fails
            std::cout << "BAD example: malloc failed, constructor unsafe" << std::endl;
        }
    }

    ~BadClass() {
        free(data);
    }
};

// GOOD: Constructor with proper exception safety (RAII)
class GoodClass {
    int* data;
public:
    GoodClass(size_t size) : data(nullptr) {
        try {
            data = new int[size]; // may throw std::bad_alloc
        } catch (const std::bad_alloc& e) {
            std::cerr << "GOOD example: allocation failed: " << e.what() << std::endl;
            throw; // Rethrow or handle appropriately
        }
    }

    ~GoodClass() {
        delete[] data;
    }
};

int main() {
    // BAD example
    BadClass* bad = new BadClass(1000000000); // may fail silently

    // GOOD example
    try {
        GoodClass good(1000000000); // safely handles allocation failure
    } catch (...) {
        std::cerr << "Caught exception in GOOD example" << std::endl;
    }

    delete bad;
    return 0;
}
