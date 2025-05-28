#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// Function to run in a separate thread
void delayedMessage() {
    cout << "Thread started, waiting for 60 seconds..." << endl;

    // Sleep for 60 seconds or 1 minute
    this_thread::sleep_for(std::chrono::seconds(60));

    cout << "Thread resumed after sleep!" << endl;
}

int main() {
    // Create and start the thread
    thread t(delayedMessage);

    // Wait for the thread to finish
    t.join();

    cout << "Main function finished." << endl;

    return 0;
}
