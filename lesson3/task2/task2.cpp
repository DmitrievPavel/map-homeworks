#include <iostream>
#include <vector>
#include <algorithm>
#include <future>

template <typename Iterator, typename Func>
void parallel_for_each(Iterator first, Iterator last, Func f)
{
    size_t length = std::distance(first, last);
    size_t chunk_size = 2;
    if (length <= chunk_size)
    {
        std::for_each(first, last, f);
    }
    else
    {
        Iterator mid = first;
        std::advance(mid, length / 2);
        std::future<void> first_half = std::async(parallel_for_each<Iterator, Func>, first, mid, f);
        parallel_for_each(mid, last, f);
        first_half.get();
    }
}

int main()
{
    std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    parallel_for_each(nums.begin(), nums.end(), [](int& n) { n *= 2; });

    for (const int& n : nums)
    {
        std::cout << n << " ";
    }

    return 0;
}