#include <iostream>
#include <csignal>
#include <cstdlib>

// BAD: Allocating memory in a signal handler (violation)
void bad_signal_handler(int signum) {
    // Unsafe: malloc inside signal handler
    char* buffer = (char*)malloc(100); 
    if (buffer) {
        buffer[0] = 'A';
        std::cout << "BAD example: signal " << signum << " allocated memory" << std::endl;
        free(buffer);
    }
}

// GOOD: Avoid memory allocation in signal handler
char preallocated_buffer[100]; // Pre-allocated memory

void good_signal_handler(int signum) {
    // Safe: Use pre-allocated memory
    preallocated_buffer[0] = 'A';
    std::cout << "GOOD example: signal " << signum << " used pre-allocated memory" << std::endl;
}

int main() {
    // Register signal handlers
    std::signal(SIGINT, bad_signal_handler);   // Vulnerable
    std::signal(SIGTERM, good_signal_handler); // Safe

    std::cout << "Press Ctrl+C to test signal handlers..." << std::endl;
    while (true) {
        // Wait for signal
    }

    return 0;
}
