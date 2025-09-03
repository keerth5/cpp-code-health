#include <iostream>

// BAD: Line exceeds 80 characters (violation)
void bad_example() {
    std::cout << "BAD example: This is a very long line of code that exceeds the eighty character limit and should be broken." << std::endl;
}

// GOOD: Break long lines into multiple lines
void good_example() {
    std::cout << "GOOD example: This is a long line of code that has been broken "
                 "into multiple lines to stay within the 80 character limit."
              << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
