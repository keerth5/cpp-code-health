#include <iostream>

// BAD: Using magic numbers directly
void bad_example(int status) {
    std::cout << "BAD example:" << std::endl;
    if (status == 404) { // Magic number
        std::cout << "Error: Not Found" << std::endl;
    }
    if (status == 500) { // Magic number
        std::cout << "Error: Internal Server Error" << std::endl;
    }
}

// GOOD: Using named constants
const int HTTP_NOT_FOUND = 404;
const int HTTP_INTERNAL_ERROR = 500;

void good_example(int status) {
    std::cout << "\nGOOD example:" << std::endl;
    if (status == HTTP_NOT_FOUND) {
        std::cout << "Error: Not Found" << std::endl;
    }
    if (status == HTTP_INTERNAL_ERROR) {
        std::cout << "Error: Internal Server Error" << std::endl;
    }
}

int main() {
    int status_code = 404;

    bad_example(status_code);
    good_example(status_code);

    return 0;
}
