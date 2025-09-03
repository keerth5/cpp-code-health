#include <iostream>

// BAD: Missing space after comma (violation)
void bad_example(int a,int b,int c) {
    std::cout << "BAD example: a=" << a << ", b=" << b << ", c=" << c << std::endl;
}

// GOOD: Proper space after comma
void good_example(int a, int b, int c) {
    std::cout << "GOOD example: a=" << a << ", b=" << b << ", c=" << c << std::endl;
}

int main() {
    bad_example(1,2,3);   // BAD
    good_example(1, 2, 3); // GOOD

    return 0;
}
