#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void sumVectorspart(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>& result, int start, int end) {

	for (int i = start; i < end; ++i) {
		result[i] = vec1[i] + vec2[i];
	}
}

void sumVectors(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>& result, int countThreads) {
	int partsize = vec1.size() / countThreads;
	std::vector<std::thread> threads;

	for (int i = 0; i < countThreads; ++i) {
		int start = i * partsize;
		int end = (i == countThreads - 1) ? vec1.size() : (i + 1) * partsize;
		threads.push_back(std::thread(sumVectorspart, std::ref(vec1), std::ref(vec2), std::ref(result), start, end));
	}

	for (auto& thread : threads) {
		thread.join();
	}
}

void fillVectors(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>& res, int countelem) {

	for (int i = 0; i < countelem; ++i) {
		vec1.push_back(i);
		vec2.push_back(i);
		res.push_back(0);
	}
}

void clearVectors(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>& res) {
	vec1.clear();
	vec2.clear();
	res.clear();
}

void go(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>& res, int countelem, int countThreads) {

	fillVectors(vec1, vec2, res, countelem);
	auto start = std::chrono::steady_clock::now();
	sumVectors(vec1, vec2, res, countThreads);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << elapsed_seconds.count() << "\t";
	clearVectors(vec1, vec2, res);

}

int main() {

	int real = std::thread::hardware_concurrency();
	std::cout << "Concurrent threads are supported: " << real << std::endl;
	std::vector<int> vec1;
	std::vector<int> vec2;
	std::vector<int> res;
	std::cout << "\t   1000\t\t10000\t\t100000\t\t1000000" << std::endl;


	int countThreads = 1;
	std::cout << countThreads << " threads: ";

	int countelem = 1000;
	go(vec1, vec2, res, countelem, countThreads);

	countelem = 10000;
	go(vec1, vec2, res, countelem, countThreads);

	countelem = 100000;
	go(vec1, vec2, res, countelem, countThreads);

	countelem = 1000000;
	go(vec1, vec2, res, countelem, countThreads);
	std::cout << std::endl;


	countThreads = 2;
	std::cout << countThreads << " threads: ";

	countelem = 1000;
	go(vec1, vec2, res, countelem, countThreads);

	countelem = 10000;
	go(vec1, vec2, res, countelem, countThreads);

	countelem = 100000;
	go(vec1, vec2, res, countelem, countThreads);

	countelem = 1000000;
	go(vec1, vec2, res, countelem, countThreads);
	std::cout << std::endl;


	countThreads = 4;
	std::cout << countThreads << " threads: ";

	countelem = 1000;
	go(vec1, vec2, res, countelem, countThreads);

	countelem = 10000;
	go(vec1, vec2, res, countelem, countThreads);

	countelem = 100000;
	go(vec1, vec2, res, countelem, countThreads);

	countelem = 1000000;
	go(vec1, vec2, res, countelem, countThreads);
	std::cout << std::endl;


	countThreads = 8;
	std::cout << countThreads << " threads: ";

	countelem = 1000;
	go(vec1, vec2, res, countelem, countThreads);

	countelem = 10000;
	go(vec1, vec2, res, countelem, countThreads);

	countelem = 100000;
	go(vec1, vec2, res, countelem, countThreads);

	countelem = 1000000;
	go(vec1, vec2, res, countelem, countThreads);
	std::cout << std::endl;


	countThreads = 16;
	std::cout << countThreads << " threads: ";

	countelem = 1000;
	go(vec1, vec2, res, countelem, countThreads);

	countelem = 10000;
	go(vec1, vec2, res, countelem, countThreads);

	countelem = 100000;
	go(vec1, vec2, res, countelem, countThreads);

	countelem = 1000000;
	go(vec1, vec2, res, countelem, countThreads);
	std::cout << std::endl;

	return 0;
}
