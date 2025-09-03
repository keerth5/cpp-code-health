#include <iostream>

// BAD: Using Hungarian notation (violation)
void bad_example() {
    int iCount = 10;
    float fValue = 3.14;
    char* pszName = (char*)"Example";

    std::cout << "BAD example: iCount=" << iCount 
              << ", fValue=" << fValue 
              << ", pszName=" << pszName << std::endl;
}

// GOOD: Descriptive variable names without Hungarian notation
void good_example() {
    int count = 10;
    float value = 3.14;
    char* name = (char*)"Example";

    std::cout << "GOOD example: count=" << count 
              << ", value=" << value 
              << ", name=" << name << std::endl;
}

int main() {
    bad_example();
    good_example();

    return 0;
}
