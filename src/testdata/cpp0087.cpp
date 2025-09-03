#include <iostream>
#include <csignal>
#include <unistd.h>
#include <cstdio>
#include <cstring>
#include <atomic>

// BAD: Signal handler using non-reentrant functions
void bad_handler(int signum) {
    // Unsafe: printf is not async-signal-safe
    printf("BAD example: Caught signal %d\n", signum);
}

// GOOD: Signal handler using only async-signal-safe functions
std::atomic<bool> signal_received(false);
void good_handler(int signum) {
    // Safe: set a flag (atomic) to be handled in main loop
    signal_received.store(true);
}

int main() {
    // BAD example
    std::signal(SIGINT, bad_handler);
    std::cout << "Press Ctrl+C for BAD example (unsafe)...\n";
    sleep(1); // wait briefly for demonstration

    // GOOD example
    std::signal(SIGTERM, good_handler);
    std::cout << "Press Ctrl+\\ or send SIGTERM for GOOD example (safe)...\n";
    sleep(1); // wait briefly for demonstration

    if (signal_received.load()) {
        std::cout << "GOOD example: Signal safely detected in main loop.\n";
    }

    return 0;
}
