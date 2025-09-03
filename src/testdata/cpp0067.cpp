#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

int shared_var = 0; // Shared global variable

// BAD: Unsynchronized access to shared variable (violation)
void bad_increment() {
    for (int i = 0; i < 1000; ++i) {
        shared_var++; // Race condition if multiple threads run this
    }
}

// GOOD: Synchronized access using mutex
std::mutex mtx;
int safe_shared_var = 0;

void good_increment() {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Lock protects access
        safe_shared_var++;
    }
}

int main() {
    // BAD example with race condition
    std::vector<std::thread> threads_bad;
    for (int i = 0; i < 4; ++i) {
        threads_bad.emplace_back(bad_increment);
    }
    for (auto &t : threads_bad) t.join();
    std::cout << "BAD example: shared_var = " << shared_var << std::endl;

    // GOOD example with mutex
    std::vector<std::thread> threads_good;
    for (int i = 0; i < 4; ++i) {
        threads_good.emplace_back(good_increment);
    }
    for (auto &t : threads_good) t.join();
    std::cout << "GOOD example: safe_shared_var = " << safe_shared_var << std::endl;

    return 0;
}
