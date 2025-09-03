#include <iostream>

// BAD: Function name starts with uppercase (violation)
void MyFunction() {
    std::cout << "BAD example: MyFunction called" << std::endl;
}

// GOOD: Function name follows naming convention
void myFunction() { // camelCase
    std::cout << "GOOD example: myFunction called" << std::endl;
}

void my_function() { // snake_case
    std::cout << "GOOD example: my_function called" << std::endl;
}

int main() {
    MyFunction();    // BAD
    myFunction();    // GOOD
    my_function();   // GOOD

    return 0;
}
