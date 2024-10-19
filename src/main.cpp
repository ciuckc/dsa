#include <algorithm>
#include <iostream>
#include <vector>

#include "Algorithm.hpp"
#include "PriorityQueue.hpp"

int main()
{
    std::vector<int> x = {6, 4, 5, 3, 1, 0, 2};
    std::cout << std::is_heap(x.begin(), x.end(), std::greater{});
    CS::make_heap(x.begin(), x.end(), std::greater{});
    std::cout << ' ' <<  std::is_heap(x.begin(), x.end(), std::greater{}) << '\n';
    for (auto i : x)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    CS::pop_heap(x.begin(), x.end(), std::greater{});
    x.pop_back();
    std::cout << std::is_heap(x.begin(), x.end(), std::greater{}) << '\n';
    for (auto i : x)
    {
        std::cout << i << ' ';
    }
}
