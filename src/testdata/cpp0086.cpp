#include <iostream>
#include <cstring>

// Mock function simulating recv()
int recv(int socket, char* buffer, size_t size, int flags) {
    // Simulate received data from network
    strncpy(buffer, "network_data", size - 1);
    buffer[size - 1] = '\0';
    return strlen(buffer);
}

// BAD: Using network data without validation
void bad_example() {
    char buffer[100];
    recv(0, buffer, sizeof(buffer), 0);
    // Directly using received data without validation
    std::cout << "BAD example: Received = " << buffer << std::endl;
}

// GOOD: Validate network data before using
void good_example() {
    char buffer[100];
    int bytes = recv(0, buffer, sizeof(buffer), 0);

    // Simple validation: length check and allowed characters
    if (bytes > 0 && bytes < sizeof(buffer)) {
        bool valid = true;
        for (int i = 0; i < bytes; ++i) {
            if (!isalnum(buffer[i]) && buffer[i] != '_') {
                valid = false;
                break;
            }
        }

        if (valid) {
            std::cout << "GOOD example: Validated network data = " << buffer << std::endl;
        } else {
            std::cout << "GOOD example: Invalid network data received" << std::endl;
        }
    }
}

int main() {
    bad_example();   // Unsafe usage
    good_example();  // Safe, validated input

    return 0;
}
