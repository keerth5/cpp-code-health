#include <iostream>

// BAD: Variable names start with uppercase (violation)
void bad_example() {
    int MyVariable = 10;
    float AnotherVar = 3.14;

    std::cout << "BAD example: MyVariable = " << MyVariable 
              << ", AnotherVar = " << AnotherVar << std::endl;
}

// GOOD: Variable names follow naming conventions
void good_example() {
    int myVariable = 10;      // camelCase
    float my_variable = 3.14; // snake_case

    std::cout << "GOOD example: myVariable = " << myVariable 
              << ", my_variable = " << my_variable << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
