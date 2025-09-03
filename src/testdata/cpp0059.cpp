#include <iostream>
#include <cstdlib>

struct Data {
    int value;
};

// BAD: Use after free (violation)
void bad_example() {
    Data* ptr = (Data*)malloc(sizeof(Data));
    ptr->value = 10;

    free(ptr); // Memory freed

    // Use after free - undefined behavior
    ptr->value = 20;
    std::cout << "BAD example: ptr->value = " << ptr->value << std::endl;
}

// GOOD: Set pointer to NULL after free
void good_example() {
    Data* ptr = (Data*)malloc(sizeof(Data));
    ptr->value = 10;

    free(ptr);
    ptr = NULL; // Avoid use after free

    if (ptr != NULL) {
        ptr->value = 20; // Safe check
    }
    std::cout << "GOOD example: ptr safely set to NULL" << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
