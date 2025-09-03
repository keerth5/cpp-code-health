#include <iostream>
#include <string>
#include <sstream>

// Simulated deserialization function
struct Data {
    int id;
    std::string name;
};

// BAD: Unsafe deserialization from untrusted input (violation)
Data bad_deserialize(const std::string& user_input) {
    Data d;
    std::istringstream ss(user_input);

    // Unsafe: no validation, user can inject malicious data
    ss >> d.id >> d.name;
    std::cout << "BAD example: deserialized id=" << d.id << ", name=" << d.name << std::endl;

    return d;
}

// GOOD: Safe deserialization with validation
Data good_deserialize(const std::string& user_input) {
    Data d;
    std::istringstream ss(user_input);

    int temp_id;
    std::string temp_name;

    // Validate input: e.g., check numeric range, string length
    if ((ss >> temp_id >> temp_name) && temp_id > 0 && temp_name.size() < 50) {
        d.id = temp_id;
        d.name = temp_name;
        std::cout << "GOOD example: deserialized id=" << d.id << ", name=" << d.name << std::endl;
    } else {
        std::cerr << "GOOD example: invalid input, deserialization aborted" << std::endl;
    }

    return d;
}

int main() {
    std::string malicious_input = "999999 MaliciousUser"; // Example untrusted input
    std::string safe_input = "42 Alice";

    bad_deserialize(malicious_input);  // Vulnerable
    good_deserialize(safe_input);      // Safe

    return 0;
}
