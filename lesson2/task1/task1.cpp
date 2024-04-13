#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>


void inc_count(std::atomic<int>& count,const int& max) {
    while (1) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (count.load() < max) {
            count.fetch_add(1);
            //count.fetch_add(1, std::memory_order_relaxed);
            std::cout << "Client. count = " << count.load() << std::endl;
        }
        else {
            break;
        }
    }
}

void dec_count(std::atomic<int>& count) {
    while (1) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        count.fetch_sub(1);
        //count.fetch_sub(1, std::memory_order_relaxed);
        std::cout << "Operator. count = " << count.load() << std::endl;
        if (count.load() == 0) {
            break;
        }
    }
}
int main()
{
    std::atomic<int> count(0);
    const int max = 10;
    std::thread t1(inc_count, std::ref(count), std::ref(max));
    std::thread t2(dec_count, std::ref(count));
    t1.join();
    t2.join();

    return 0;
}