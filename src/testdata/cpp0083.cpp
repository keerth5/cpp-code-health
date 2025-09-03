#include <iostream>
#include <thread>
#include <mutex>

// Shared resources
std::mutex mutex1;
std::mutex mutex2;

// BAD: Acquiring multiple locks in different orders (deadlock prone)
void bad_thread1() {
    std::lock_guard<std::mutex> lock1(mutex1);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::lock_guard<std::mutex> lock2(mutex2);
    std::cout << "BAD example: Acquired mutex1 then mutex2" << std::endl;
}

void bad_thread2() {
    std::lock_guard<std::mutex> lock2(mutex2);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::lock_guard<std::mutex> lock1(mutex1);
    std::cout << "BAD example: Acquired mutex2 then mutex1" << std::endl;
}

// GOOD: Always acquire locks in same order or use std::scoped_lock
void good_thread_func() {
    // std::scoped_lock avoids deadlocks by locking both simultaneously
    std::scoped_lock lock(mutex1, mutex2);
    std::cout << "GOOD example: Acquired both mutexes safely" << std::endl;
}

int main() {
    // BAD example (may deadlock)
    std::thread t1(bad_thread1);
    std::thread t2(bad_thread2);

    t1.join();
    t2.join();

    // GOOD example
    std::thread t3(good_thread_func);
    std::thread t4(good_thread_func);

    t3.join();
    t4.join();

    return 0;
}
