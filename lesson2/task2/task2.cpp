#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>


std::mutex consoleMutex;

void progressBar(int threadNumber, int length)
{
    int progress = 0;
    std::mutex mtx;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < length; i++)
    {
        {
            std::lock_guard<std::mutex> lock(consoleMutex);
            std::cout << "\033[s";  
            std::cout << "\033[" << threadNumber << ";0H";  
            std::cout << "Thread " << threadNumber << " (ID: " << std::this_thread::get_id() << "): [";
            for (int j = 0; j <= i; j++)
            {
                std::cout << "|";
            }
            for (int j = i + 1; j < length; j++)
            {
                std::cout << " ";
            }
            std::cout << "]" << (progress + 1) * 100 / length << "%" << std::flush;  

            std::cout << "\033[u";  
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        progress++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "\033[70C" << "Thread " << threadNumber << " finished in " << elapsed.count() << " seconds" << std::endl;
}

int main()
{
    int numThreads = 4; 
    int length = 40;    

    std::cout << "\033[2J";  
    std::cout << "\033[?25l";

    std::vector<std::thread> threads;


    for (int i = 0; i < numThreads; i++)
    {
        threads.push_back(std::thread(progressBar, i + 1, length));
    }

 
    for (std::thread& t : threads)
    {
        t.join();
    }


    std::cout << "\033[?25h"; 

    return 0;
}