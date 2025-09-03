#include <iostream>

// BAD: Inconsistent indentation (violation)
void bad_example() {
	std::cout << "BAD example line 1 (tab)" << std::endl;  // tab
    std::cout << "BAD example line 2 (spaces)" << std::endl; // spaces
	 std::cout << "BAD example line 3 (mixed)" << std::endl;  // mixed
}

// GOOD: Consistent indentation using 4 spaces
void good_example() {
    std::cout << "GOOD example line 1" << std::endl;
    std::cout << "GOOD example line 2" << std::endl;
    std::cout << "GOOD example line 3" << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
