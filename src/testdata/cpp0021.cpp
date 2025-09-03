#include <iostream>

// BAD: Using goto (violation)
void bad_example() {
    std::cout << "BAD example (using goto):" << std::endl;
    int i = 0;

start_loop:
    if (i >= 5) goto end_loop; // Jumping around makes code hard to follow
    std::cout << "i = " << i << std::endl;
    i++;
    goto start_loop;

end_loop:
    std::cout << "Finished BAD example." << std::endl;
}

// GOOD: Using structured control flow
void good_example() {
    std::cout << "\nGOOD example (structured loop):" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "i = " << i << std::endl;
    }
    std::cout << "Finished GOOD example." << std::endl;
}

int main() {
    // ⚠️ BAD example works but creates spaghetti code
    bad_example();

    good_example();

    return 0;
}
