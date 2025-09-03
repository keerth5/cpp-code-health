#include <iostream>
#include <string>

// BAD: Function with too many parameters (violation)
void bad_example(int a, int b, int c, int d, int e, int f, int g) {
    std::cout << "BAD example sum: " << (a + b + c + d + e + f + g) << std::endl;
}

// GOOD: Group parameters using struct
struct Params {
    int a, b, c, d, e, f, g;
};

void good_example(const Params& p) {
    std::cout << "GOOD example sum: " << (p.a + p.b + p.c + p.d + p.e + p.f + p.g) << std::endl;
}

int main() {
    // BAD example
    bad_example(1, 2, 3, 4, 5, 6, 7);

    // GOOD example
    Params p = {1, 2, 3, 4, 5, 6, 7};
    good_example(p);

    return 0;
}
