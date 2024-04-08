#include <iostream>
#include <chrono>
#include <thread>

void inc_count(int& count, int max) {
    while (1) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (count < max) {
            count++;
            std::cout << "Client. count = " << count << std::endl;
        }
        else {
            break;
        }
    }
}

void dec_count(int& count) {
    while (1) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        count--;
        std::cout << "Operator. count = " << count << std::endl;
        if (count == 0) {
            break;
        }
    }
}

int main()
{
    int count = 0;
    const int max = 10;
    std::thread t1(inc_count, std::ref(count), max);
    std::thread t2(dec_count, std::ref(count));
    t1.join();
    t2.join();

    return 0;
}

