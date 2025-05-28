#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
// Function that sleeps until a specific time
void waitUntilExample()
{
    // Get the current time
    auto now = std::chrono::system_clock::now();

    // Set the target time to 5 seconds from now
    auto wakeUpTime = now + std::chrono::seconds(15);

    cout << "Thread will sleep until 15 seconds later..." << endl;

    // Sleep until the specified time
    this_thread::sleep_until(wakeUpTime);

    cout << "Thread woke up after 15 seconds!" << endl;
}

int main()
{
    // Start the thread
    thread t(waitUntilExample);

    // Wait for the thread to finish
    t.join();

    cout << "Main function done." << endl;

    return 0;
}
