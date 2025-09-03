#include <iostream>

// BAD: Base class with virtual function but no virtual destructor
class BadBase {
public:
    virtual void func() {
        std::cout << "BadBase func called" << std::endl;
    }
    // Missing virtual destructor → deleting derived object via base pointer is undefined
};

class BadDerived : public BadBase {
public:
    ~BadDerived() {
        std::cout << "BadDerived destructor called" << std::endl;
    }
};

// GOOD: Base class with virtual destructor
class GoodBase {
public:
    virtual void func() {
        std::cout << "GoodBase func called" << std::endl;
    }
    virtual ~GoodBase() {
        std::cout << "GoodBase virtual destructor called" << std::endl;
    }
};

class GoodDerived : public GoodBase {
public:
    ~GoodDerived() {
        std::cout << "GoodDerived destructor called" << std::endl;
    }
};

int main() {
    std::cout << "BAD example:" << std::endl;
    BadBase* bad = new BadDerived();
    delete bad; // Undefined behavior: BadDerived destructor may not run

    std::cout << "\nGOOD example:" << std::endl;
    GoodBase* good = new GoodDerived();
    delete good; // Safe: both GoodDerived and GoodBase destructors run

    return 0;
}
