#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std::chrono_literals;

int main() {
    // Pre-C++11 platform dependent threading libraries had to be used in order to create threads.
    // C++11 introduced std::thread. A platform independent way to create a thread.
    std::thread myThread([] {
        while (true) {
            std::cout << "Running thread..." << std::endl;
            std::this_thread::sleep_for(2000ms);
        }
    });
    myThread.join();























    // C++11 also introduced std::mutex to prevent concurrent access to shared state.
    std::mutex myMutex;
    int sharedNumber = 0;
    std::thread incrementer([&myMutex, &sharedNumber] {
        for (int i = 0; i < 1000000; ++i) {
            myMutex.lock();
            sharedNumber++;
            myMutex.unlock();
        }
    });
    std::thread decrementer([&myMutex, &sharedNumber] {
        for (int i = 0; i < 1000000; ++i) {
            myMutex.lock();
            sharedNumber--;
            myMutex.unlock();
        }
    });

    incrementer.join();
    decrementer.join();
    std::cout << "sharedNumber = " << sharedNumber << std::endl;

    // C++11 and 17 introduced several RAII mechanisms make sure mutex unlock isn't forgotten.
    {
        // Locks mutex upon construction
        std::scoped_lock lck{ myMutex };

        // Unlocks mutex upon deconstruction, e.g. when leaving scope.
    }

    // Alternatively, if intermediate unlocking is needed
    {
        std::unique_lock lck{ myMutex };

        lck.unlock();
        
        lck.lock();

        // Is still unlocked upon leaving scope.
    }

}
