#include <iostream>
#include <string>

// BAD: Hardcoded cryptographic key or password (violation)
void bad_example() {
    const char* hardcoded_key = "MySecretKey123";  // Exposed key
    const std::string password = "SuperPass987";

    std::cout << "BAD example: key = " << hardcoded_key << std::endl;
    std::cout << "BAD example: password = " << password << std::endl;
}

// GOOD: Load keys and passwords from secure configuration/environment
void good_example() {
    // Example: read from environment variables (safe practice)
    const char* key = std::getenv("APP_KEY");
    const char* password = std::getenv("APP_PASSWORD");

    if (key && password) {
        std::cout << "GOOD example: key loaded from environment" << std::endl;
        std::cout << "GOOD example: password loaded from environment" << std::endl;
    } else {
        std::cerr << "GOOD example: key or password not set in environment" << std::endl;
    }
}

int main() {
    bad_example();
    good_example();

    return 0;
}
