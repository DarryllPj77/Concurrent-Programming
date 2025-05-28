#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;            // Shared resource
mutex counterMutex;    // Mutex to protect access

void incrementCounter(const string & name) {                        
    for (int i = 0; i < 5; ++i) {
        // Lock the mutex before accessing shared resource
        counterMutex.lock();
        ++counter;
        cout << name << " incremented counter to " << counter << endl;
        counterMutex.unlock();

        // Optional sleep for readability
        this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    thread t1(incrementCounter, "Thread A");
    thread t2(incrementCounter, "Thread B");

    t1.join();
    t2.join();

    cout << "Final counter value: " << counter << endl;

    return 0;
}
