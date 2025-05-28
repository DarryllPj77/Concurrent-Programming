#include <iostream>
#include <thread>

using namespace std;
// This program demonstrates the use of threads in C++.
// Function to run in a thread
void runTask(const std::string& name) {
    for (int i = 1; i <= 5; ++i) {
        cout << name << " running iteration " << i << endl;

        // Voluntarily yield control to let other threads run
        this_thread::yield();
    }
}

int main() {
    // Start two threads
    thread t1(runTask, "Thread 1");
    thread t2(runTask, "Thread 2");

    // Wait for both threads to finish
    t1.join();
    t2.join();

    cout << "Both threads finished." << endl;

    return 0;
}
// This code demonstrates how to use std::this_thread::yield() to allow other threads to run.
// The yield function is called within a loop in the runTask function, allowing the threads to yield control