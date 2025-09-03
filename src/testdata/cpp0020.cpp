#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

void bad_example() {
    std::cout << "BAD example (thread-unsafe static variable):" << std::endl;

    auto worker = []() {
        // BAD: Static variable modified by multiple threads without synchronization
        static int counter = 0;
        for (int i = 0; i < 1000; ++i) {
            counter++; // Data race
        }
        std::cout << "Counter in thread: " << counter << std::endl;
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(worker);
    }
    for (auto& t : threads) t.join();
}

void good_example() {
    std::cout << "\nGOOD example (thread-safe static variable):" << std::endl;

    auto worker = []() {
        // GOOD: Use std::atomic to safely modify static variable across threads
        static std::atomic<int> counter(0);
        for (int i = 0; i < 1000; ++i) {
            counter++;
        }
        std::cout << "Counter in thread: " << counter.load() << std::endl;
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(worker);
    }
    for (auto& t : threads) t.join();
}

int main() {
    // ⚠️ Warning: BAD example has data races, output is undefined
    // bad_example();

    good_example();
    return 0;
}
