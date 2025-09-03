#include <iostream>

void bad_example() {
    double d = 3.14;

    // BAD: C-style cast (violation)
    int x = (int)d;  // C-style cast
    std::cout << "Bad example value: " << x << std::endl;
}

void good_example() {
    double d = 3.14;

    // GOOD: Use static_cast (C++ style)
    int x = static_cast<int>(d);
    std::cout << "Good example value: " << x << std::endl;

    // Example with pointer reinterpretation
    void* ptr = &d;
    intptr_t addr = reinterpret_cast<intptr_t>(ptr);
    int* int_ptr = static_cast<int*>(ptr); // Proper C++ casts
}

int main() {
    std::cout << "Running bad example...\n";
    bad_example();

    std::cout << "Running good example...\n";
    good_example();

    return 0;
}
