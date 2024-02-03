//============================================================================
// Name        : CSC 450 Module 7 PP Milestone Part 1.cpp
// Author      : Zach Winterton
// Date        : 02/03/2024
// Description : C++ program designed to exhibit concurrency concepts. Program has two threads, thread1 for counting up to 20 and thread2 for counting down to 0.
// The std::mutex is used to synchronize access to shared resources (in this case, the console output).
// The std::lock_guard is employed to automatically lock and unlock the mutex, ensuring proper synchronization.
//============================================================================

// Include necessary header files
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// Define global mutex
std::mutex mutex1;

// Define countUp() function
void countUp() {
	for(int i = 1; i <= 20; ++i) {
		// Lock mutex to protect shared resources
		std::lock_guard<std::mutex> lock(mutex1);
		// Print count
		std::cout << "Thread 1: Counting up -- " << i << std::endl;
		// Sleeping thread for a duration
		std::this_thread::sleep_for(std::chrono::milliseconds(400));
	}
}

// Define countDown() function
void countDown() {
	for(int i = 20; i >= 0; --i) {
		// Lock mutex to protect shared resources
		std::lock_guard<std::mutex> lock(mutex1);
		// Print count
		std::cout << "Thread 2: Counting down -- " << i << std::endl;
		// Sleeping thread for a duration
		std::this_thread::sleep_for(std::chrono::milliseconds(400));
	}
}

// Main() function
int main() {
	// Creating thread1 for countUp and joining it
	std::thread thread1(countUp);
	thread1.join();
	// Creating thread2 for countDown and joining it
	std::thread thread2(countDown);
	thread2.join();

	return 0;
}
