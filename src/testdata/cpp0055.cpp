#include <iostream>
#include <regex>
#include <string>

// BAD: Weak password validation (violation)
bool bad_validate_password(const std::string& password) {
    // Only checks for at least one digit
    std::regex weak_regex(".*[0-9]{1}.*");
    return std::regex_match(password, weak_regex);
}

// GOOD: Strong password validation
bool good_validate_password(const std::string& password) {
    // Require at least 8 characters, 1 uppercase, 1 lowercase, 1 digit, 1 special character
    std::regex strong_regex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!@#$%^&*()_+\\-=\\[\\]{};':\"\\\\|,.<>/?]).{8,}$");
    return std::regex_match(password, strong_regex);
}

int main() {
    std::string password1 = "pass123";
    std::string password2 = "StrongP@ss1";

    std::cout << "BAD validation (pass123): " << bad_validate_password(password1) << std::endl;
    std::cout << "GOOD validation (StrongP@ss1): " << good_validate_password(password2) << std::endl;

    return 0;
}
