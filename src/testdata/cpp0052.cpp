#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

// BAD: TOCTOU race condition (violation)
void bad_example(const char* filename) {
    // Check if file exists
    if (access(filename, F_OK) == 0) {
        // Open file after check
        int fd = open(filename, O_RDONLY);
        if (fd != -1) {
            std::cout << "BAD example: opened file successfully" << std::endl;
            close(fd);
        }
    }
}

// GOOD: Avoid TOCTOU by using open() directly and checking errors
void good_example(const char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        std::cerr << "GOOD example: failed to open file, errno=" << errno << std::endl;
        return;
    }
    std::cout << "GOOD example: opened file successfully" << std::endl;
    close(fd);
}

int main() {
    const char* filename = "testfile.txt";

    bad_example(filename);
    good_example(filename);

    return 0;
}
