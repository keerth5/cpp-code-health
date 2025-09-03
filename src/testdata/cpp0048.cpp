#include <iostream>

// BAD: Single character variable names in a long function (violation)
void bad_example() {
    int a = 0;
    int b = 1;
    int c = 2;
    int d = 3;
    int e = 4;
    int f = 5;
    int g = 6;
    int h = 7;
    int i = 8;
    int j = 9;
    int k = 10;
    int l = 11;
    int m = 12;
    int n = 13;
    int o = 14;
    int p = 15;
    int q = 16;
    int r = 17;
    int s = 18;
    int t = 19;
    int u = 20;
    int v = 21;
    int w = 22;
    int x = 23;
    int y = 24;
    int z = 25;

    std::cout << "BAD example: single character variable names in long function" << std::endl;
}

// GOOD: Descriptive variable names
void good_example() {
    int index = 0;
    int counter = 1;
    int total = 2;
    int sum = 3;
    int maxValue = 4;
    int minValue = 5;

    std::cout << "GOOD example: descriptive variable names in long function" << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
