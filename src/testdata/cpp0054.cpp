#include <iostream>
#include <cstdlib>   // for rand()
#include <ctime>     // for time()
#include <random>    // for C++11 secure random

// BAD: Using rand() for security purposes (violation)
void bad_example() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // seed
    int key = std::rand();  // Not secure
    std::cout << "BAD example: insecure key = " << key << std::endl;
}

// GOOD: Use cryptographically secure random
void good_example() {
    std::random_device rd; // non-deterministic random
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<int> dist(0, INT32_MAX);

    int key = dist(gen);
    std::cout << "GOOD example: secure key = " << key << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
