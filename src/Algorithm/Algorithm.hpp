//
// Created by scristia on 18-10-24.
//

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <iostream>
#include <utility>

namespace CS
{
    template <typename RandomIt, typename Compare>
    void make_heap(RandomIt first, RandomIt last, Compare comp)
    {
        if (first == last)
        {
            return;
        }
        auto size = last - first - 1;
        for (auto curr = first + size; curr != first; --curr)
        {
            auto curr_node = curr;
            while (first < curr_node && !comp(*curr_node, *(first + (curr_node - first) / 2)))
            {
                using std::swap;
                swap(*curr_node, *(first + (curr_node - first) / 2));
                curr_node =  first + (curr_node - first) / 2;
            }
        }
    }
};
#endif //ALGORITHM_HPP
