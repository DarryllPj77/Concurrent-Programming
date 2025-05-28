#include <iostream>
#include <thread>

// Function to run in a thread
void showThreadInfo() {
    std::cout << "Thread function is running. Thread ID: "
              << std::this_thread::get_id() << std::endl;
}

int main() {
    std::thread t(showThreadInfo);

    // Print the ID of the newly created thread
    std::cout << "Main created thread with ID: " << t.get_id() << std::endl;

    // Wait for the thread to finish
    t.join();

    std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;

    return 0;
}
