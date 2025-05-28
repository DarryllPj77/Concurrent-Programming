#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;
//which allows a thread to voluntarily give up the CPU so other threads can run:
mutex coutMutex; // shared mutex

void task(const string& name) {
    for (int i = 1; i <= 5; ++i) {
        {
            lock_guard<mutex> lock(coutMutex);
            cout << name << " - iteration " << i << endl;
        }

        this_thread::yield();
        this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    thread t1(task, "Thread A");
    thread t2(task, "Thread B");

    t1.join();
    t2.join();

    cout << "Both threads finished cooperatively." << endl;
    return 0;
}
// This code demonstrates how to use std::this_thread::yield() to allow other threads to run.       