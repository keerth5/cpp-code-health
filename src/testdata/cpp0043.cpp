#include <iostream>

// BAD: Lines with trailing whitespace (violation)
void bad_example() {    
    std::cout << "BAD example: line has trailing spaces" << std::endl;     
    int x = 5;   
}

// GOOD: Lines without trailing whitespace
void good_example() {
    std::cout << "GOOD example: no trailing spaces" << std::endl;
    int x = 5;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
