#include <iostream>
#include <cstring>
#include <cstdint>
#include <arpa/inet.h> // For send() example (POSIX)

struct Data {
    uint32_t id;
    char name[8];
    // Potential padding bytes here
};

// BAD: Sending struct without initialization (violation)
void bad_example() {
    Data s; // Uninitialized
    s.id = 1;
    // Padding bytes may contain sensitive memory
    std::cout << "BAD example: sending uninitialized struct" << std::endl;
    // send(sockfd, &s, sizeof(s), 0); // hypothetical send
}

// GOOD: Zero out struct before use
void good_example() {
    Data s;
    memset(&s, 0, sizeof(s)); // Initialize all fields including padding
    s.id = 1;
    std::strncpy(s.name, "Alice", sizeof(s.name)-1);
    s.name[sizeof(s.name)-1] = '\0';

    std::cout << "GOOD example: struct safely initialized" << std::endl;
    // send(sockfd, &s, sizeof(s), 0); // safe send
}

int main() {
    bad_example();
    good_example();

    return 0;
}
