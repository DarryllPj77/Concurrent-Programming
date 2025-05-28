#include <iostream>
#include <thread>

void sayHello() {
    std::cout << "Hello from thread!\n";
}

int main() {
    std::thread t(sayHello);

    if (t.joinable()) {
        std::cout << "Thread is joinable. Joining now...\n";
        t.join();  // Join the thread safely
    } else {
        std::cout << "Thread is not joinable!\n";
    }

    std::cout << "Main thread continues.\n";
    return 0;
}
