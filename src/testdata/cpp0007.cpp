#include <iostream>
#include <csignal>
#include <unistd.h>

// BAD: Handler using printf (violation)
void handler_with_printf(int signum) {
    // printf is NOT async-signal-safe, can cause race conditions
    printf("Caught signal %d\n", signum);
}

// GOOD: Minimal handler using async-signal-safe functions
// Here we just write a single byte to a pipe
int pipefd[2];

void handler_with_pipe(int signum) {
    char msg = 'x';
    write(pipefd[1], &msg, 1); // write is async-signal-safe
}

int main() {
    // BAD: Registering a handler that calls printf
    signal(SIGINT, handler_with_printf);
    std::cout << "Press Ctrl+C (BAD handler active)" << std::endl;
    sleep(2);

    // GOOD: Using self-pipe trick
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    signal(SIGINT, handler_with_pipe);
    std::cout << "Press Ctrl+C (GOOD handler active)" << std::endl;

    // Main loop waits for signal notifications via pipe
    char buf;
    while (true) {
        ssize_t n = read(pipefd[0], &buf, 1);
        if (n > 0) {
            std::cout << "Signal received safely via pipe" << std::endl;
            break;
        }
    }

    return 0;
}
