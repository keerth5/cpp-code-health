#include <iostream>
#include <csignal>
#include <atomic>
#include <unistd.h>

// BAD: Shared variable accessed by signal handler without volatile
static int flag = 0;

void bad_handler(int signum) {
    flag = 1; // may not be reliably seen in main loop
}

// GOOD: Shared variable declared as volatile for signal-safe access
static volatile int safe_flag = 0;

void good_handler(int signum) {
    safe_flag = 1; // main loop reliably sees the change
}

int main() {
    // BAD example
    std::signal(SIGINT, bad_handler);
    std::cout << "Press Ctrl+C for BAD example...\n";
    sleep(1);
    if (flag) {
        std::cout << "BAD example: flag detected (may be unreliable)\n";
    } else {
        std::cout << "BAD example: flag not detected (race/optimization may occur)\n";
    }

    // GOOD example
    std::signal(SIGTERM, good_handler);
    std::cout << "Send SIGTERM for GOOD example...\n";
    sleep(1);
    if (safe_flag) {
        std::cout << "GOOD example: safe_flag detected reliably\n";
    }

    return 0;
}
