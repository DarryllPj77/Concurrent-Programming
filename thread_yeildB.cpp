#include <iostream>
#include <thread>
#include <chrono>

void task(const std::string& name) {
    for (int i = 1; i <= 5; ++i) {
        std::cout << name << " - iteration " << i << std::endl;

        // Yield control to let other threads run
        std::this_thread::yield();

        // Optional: sleep to simulate some work being done
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    // Start two threads
    std::thread t1(task, "Thread A");
    std::thread t2(task, "Thread B");

    // Wait for both threads to finish
    t1.join();
    t2.join();

    std::cout << "Both threads finished cooperatively." << std::endl;

    return 0;
}
// This code demonstrates how to use std::this_thread::yield() to allow other threads to run.
// The yield function is called within a loop in the task function, allowing the threads to yield control