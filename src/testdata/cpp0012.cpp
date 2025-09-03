#include <iostream>

void process() {
    std::cout << "Processing..." << std::endl;
}

void bad_example() {
    // BAD: Infinite loop without break (violation)
    while (1) {
        process(); // No break → runs forever
    }

    // BAD: for(;;) without break (violation)
    for (;;) {
        process(); // Infinite loop, no exit condition
    }
}

void good_example() {
    int counter = 0;

    // GOOD: while(1) with break condition
    while (1) {
        process();
        counter++;
        if (counter > 3) break; // Break ensures termination
    }

    counter = 0;

    // GOOD: for(;;) with break condition
    for (;;) {
        process();
        counter++;
        if (counter > 3) break; // Break ensures termination
    }
}

int main() {
    // ⚠️ Commented out bad_example() to avoid hanging program
    // bad_example();

    good_example();
    return 0;
}
