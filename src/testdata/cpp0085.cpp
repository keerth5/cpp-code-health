#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

// BAD: Weak seeding for security-sensitive randomness
void bad_example() {
    srand(1);           // deterministic seed
    int r1 = rand();
    int r2 = rand();
    std::cout << "BAD example: rand() outputs = " << r1 << ", " << r2 << std::endl;

    srand(time(NULL));  // predictable seed in security context
    int r3 = rand();
    int r4 = rand();
    std::cout << "BAD example: rand() with time seed = " << r3 << ", " << r4 << std::endl;
}

// GOOD: Use cryptographically secure random number generation
void good_example() {
    std::random_device rd;               // non-deterministic seed
    std::mt19937 gen(rd());              // Mersenne Twister generator
    std::uniform_int_distribution<> dis(1, 100);

    int r1 = dis(gen);
    int r2 = dis(gen);
    std::cout << "GOOD example: secure random numbers = " << r1 << ", " << r2 << std::endl;
}

int main() {
    bad_example();   // unsafe for security
    good_example();  // secure RNG

    return 0;
}
