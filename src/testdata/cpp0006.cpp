#include <iostream>
#include <climits>

int main() {
    int a = INT_MAX;
    int b = 10;

    // BAD: No overflow check (violation)
    int result_bad = a + b; // Can overflow
    std::cout << "Bad result (overflow possible): " << result_bad << std::endl;

    // GOOD: Check for overflow before addition
    int result_good = 0;
    if (a > INT_MAX - b) {
        std::cout << "Overflow detected, cannot add safely" << std::endl;
    } else {
        result_good = a + b;
        std::cout << "Safe result: " << result_good << std::endl;
    }

    // Additional safe example for subtraction
    int c = INT_MIN;
    int d = 5;
    int result_sub = 0;
    if (c < INT_MIN + d) {
        std::cout << "Underflow detected, cannot subtract safely" << std::endl;
    } else {
        result_sub = c - d;
        std::cout << "Safe subtraction result: " << result_sub << std::endl;
    }

    return 0;
}
