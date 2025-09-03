#include <iostream>

// BAD: Missing spaces around operators (violation)
void bad_example() {
    int x=5;
    int y=10;
    int sum=x+y;
    int diff=y-x;
    int prod=x*y;
    int quot=y/x;
    int mod=y%x;

    std::cout << "BAD example: sum=" << sum 
              << ", diff=" << diff 
              << ", prod=" << prod 
              << ", quot=" << quot 
              << ", mod=" << mod << std::endl;
}

// GOOD: Proper spaces around operators
void good_example() {
    int x = 5;
    int y = 10;
    int sum = x + y;
    int diff = y - x;
    int prod = x * y;
    int quot = y / x;
    int mod = y % x;

    std::cout << "GOOD example: sum=" << sum 
              << ", diff=" << diff 
              << ", prod=" << prod 
              << ", quot=" << quot 
              << ", mod=" << mod << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
