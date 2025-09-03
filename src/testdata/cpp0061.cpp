#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

// BAD: Path traversal vulnerability (violation)
void bad_example(const std::string& user_path) {
    std::ifstream file(user_path); // User input used directly
    if (file.is_open()) {
        std::cout << "BAD example: opened file " << user_path << std::endl;
        file.close();
    } else {
        std::cout << "BAD example: failed to open " << user_path << std::endl;
    }
}

// GOOD: Validate and canonicalize paths
void good_example(const std::string& user_path) {
    try {
        std::filesystem::path base_dir = "/safe/directory";
        std::filesystem::path requested = std::filesystem::canonical(base_dir / user_path);

        // Ensure requested path is within allowed directory
        if (requested.string().find(base_dir.string()) != 0) {
            std::cerr << "GOOD example: path traversal detected, access denied" << std::endl;
            return;
        }

        std::ifstream file(requested);
        if (file.is_open()) {
            std::cout << "GOOD example: opened safe file " << requested << std::endl;
            file.close();
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "GOOD example: filesystem error: " << e.what() << std::endl;
    }
}

int main() {
    std::string unsafe_path = "../../etc/passwd";   // BAD input
    std::string safe_path = "file.txt";            // Safe input

    bad_example(unsafe_path);  // Vulnerable
    good_example(unsafe_path); // Blocked
    good_example(safe_path);   // Allowed

    return 0;
}
