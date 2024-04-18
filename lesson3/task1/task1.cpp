#include <iostream>
#include <future>
#include <vector>

void findMin(std::vector<int>& vec, std::promise<size_t> promIndex, size_t i) {
	size_t minIndex = i;
	for (size_t j = i; j < vec.size(); ++j) {
		if (vec[minIndex] > vec[j]) {
			minIndex = j;
		}
	}
	promIndex.set_value(minIndex);
}

int main()
{
	std::vector<int> vec = { 3, 8, 25, 1, 43, 9, 36, 55, 2, 21, 4, 7 };
	std::cout << "Before sort: " << std::endl;
	for (const auto& i : vec) {
		std::cout << i << " ";
	}

	for (size_t i = 0; i < vec.size(); ++i) {
		std::promise<size_t> promIndex;
		auto promIndexfuture = promIndex.get_future();
		auto findIndexfuture = std::async(findMin, std::ref(vec), std::move(promIndex), i);
		auto indexMin = promIndexfuture.get();
		std::swap(vec[i], vec[indexMin]);
	}

	std::cout << "\nAfter sort: " << std::endl;
	for (const auto& i : vec) {
		std::cout << i << " ";
	}
	return 0;
}
