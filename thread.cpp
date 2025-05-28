#include <iostream>
#include <thread>

using namespace std;
// Function to run in a separate thread
void printMessage1() {
    cout << "Hello from the thread1!\n" << endl;
}

void printMessage2() {
    cout << "Hello from the thread2!" << endl;
}

int main() {
    // Create a thread and run the function
    thread t1(printMessage1);
    thread t2(printMessage2);

    // Wait for the thread to finish
    t1.join();
    t2.join();
    cout << "Hello from the main function!" << std::endl;

    return 0;
}
