#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

// Shared global variable
int shared_counter = 0;

// BAD: Threads accessing shared data without synchronization (violation)
void bad_thread_func() {
    for (int i = 0; i < 1000; ++i) {
        shared_counter++; // Race condition
    }
}

// GOOD: Threads accessing shared data with proper synchronization
std::mutex counter_mutex;
int safe_shared_counter = 0;

void good_thread_func() {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(counter_mutex);
        safe_shared_counter++; // Thread-safe
    }
}

int main() {
    // BAD example
    std::vector<std::thread> bad_threads;
    for (int i = 0; i < 4; ++i) {
        bad_threads.emplace_back(bad_thread_func);
    }
    for (auto& t : bad_threads) t.join();
    std::cout << "BAD example: shared_counter = " << shared_counter << " (may vary due to race condition)" << std::endl;

    // GOOD example
    std::vector<std::thread> good_threads;
    for (int i = 0; i < 4; ++i) {
        good_threads.emplace_back(good_thread_func);
    }
    for (auto& t : good_threads) t.join();
    std::cout << "GOOD example: safe_shared_counter = " << safe_shared_counter << std::endl;

    return 0;
}
