#include <iostream>

// BAD: Header file without include guards
// This can cause multiple definition errors if included multiple times

void bad_function() {
    std::cout << "BAD example function" << std::endl;
}

// GOOD: Header file with include guards
#ifndef INCLUDE_GUARD_EXAMPLE_H
#define INCLUDE_GUARD_EXAMPLE_H

void good_function() {
    std::cout << "GOOD example function" << std::endl;
}

#endif // INCLUDE_GUARD_EXAMPLE_H
