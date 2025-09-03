#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>

// BAD: Using system() with unsanitized user input (violation)
void bad_example(const std::string& user_command) {
    std::cout << "BAD example: executing user input directly" << std::endl;
    system(user_command.c_str()); // Vulnerable to command injection
}

// GOOD: Validate and sanitize user input before executing
void good_example(const std::string& user_command) {
    // Allow only alphanumeric and limited safe characters
    std::regex safe_regex("^[a-zA-Z0-9_\\-]+$");
    if (!std::regex_match(user_command, safe_regex)) {
        std::cerr << "GOOD example: invalid command, not executing" << std::endl;
        return;
    }

    std::string safe_command = "/usr/bin/safe_exec " + user_command;
    system(safe_command.c_str()); // Safe execution
    std::cout << "GOOD example: executed sanitized command" << std::endl;
}

int main() {
    std::string unsafe_cmd = "rm -rf /";  // BAD input
    std::string safe_cmd = "list_files";  // Allowed input

    bad_example(unsafe_cmd);
    good_example(unsafe_cmd);  // will be blocked
    good_example(safe_cmd);    // executed safely

    return 0;
}
