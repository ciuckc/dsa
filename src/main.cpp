#include <vector>

#include "Algorithm/Algorithm.hpp"
#include "PriorityQueue/PriorityQueue.hpp"
int main()
{
    std::vector<int> x = {6, 4, 5, 3, 1, 0, 2};
    std::cout <<  std::is_heap(x.begin(), x.end(), std::greater{});
}
