#include <iostream>
#include <Windows.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

class consol_parameter
{
public:
    static void SetColor(int text, int background)
    {
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }
    static void SetPosition(int x, int y)
    {
        COORD point;
        point.X = x;
        point.Y = y;
        SetConsoleCursorPosition(hStdOut, point);
    }
private:
    static HANDLE hStdOut;
};
HANDLE consol_parameter::hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

std::mutex mtx;

void progress(int threadNum, int length) {

    mtx.lock();
    consol_parameter::SetPosition(0, threadNum - 1);
    std::cout << "Thread " << threadNum << " (ID: " << std::this_thread::get_id() << ")";
    mtx.unlock();
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < length; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::lock_guard<std::mutex> lock(mtx);
        consol_parameter::SetPosition(i + 20, threadNum - 1);
        std::cout << "|";
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    mtx.lock();
    consol_parameter::SetPosition(length + 20, threadNum - 1);
    std::cout << elapsed.count();
    mtx.unlock();

    std::this_thread::sleep_for(std::chrono::seconds(5));
}

int main() {
    int numThreads = 4;
    int length = 40;
    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; i++) {
        threads.push_back(std::thread(progress, i + 1, length));
    }


    for (std::thread& t : threads) {
        t.join();
    }


    return 0;
}