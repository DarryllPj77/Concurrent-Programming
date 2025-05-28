#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
int counter = 0;
mutex mtx;

void incrementCounter(int id) {
    for (int i = 0; i < 5; ++i) {
        mtx.lock();
        ++counter;
        cout << "Thread"<<"["<< id <<"]"<< "counter: " << counter << endl;
        mtx.unlock();
    }
    cout << "Thread"<<"["<< id <<"]"<< "Just finished"<< endl;
}

int main() {
    thread t1(incrementCounter, 1);

    thread t2(incrementCounter, 2);

    t1.join();
    t2.join();

    cout << "Final counter value: " << counter << endl;
    return 0;
}
