//
// Created by scristia on 18-10-24.
//

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <functional>

namespace CS
{
    namespace detail
    {
        template <typename RandomIt, typename Distance, typename Compare>
        constexpr void push_heap(RandomIt first, Distance top_index, Distance len,
                                 Compare comp)
        {
            auto parent = (len - 1) / 2;
            while (top_index < len && comp(*(first + parent), *(first + len)))
            {
                std::swap(*(first + parent), *(first + len));
                len = parent;
                parent = (parent - 1) / 2;
            }
        }
    } // namespace detail

    template <typename RandomIt>
    constexpr void make_heap(RandomIt first, RandomIt last)
    {
        make_heap(first, last, std::less{});
    }

    template <typename RandomIt, typename Compare>
    constexpr void make_heap(RandomIt first, RandomIt last, Compare comp)
    {
        auto distance = last - first;
        if (distance <= 1)
        {
            return;
        }
        auto len = distance - 1;
        while (len > 0)
        {
            detail::push_heap(first, decltype(len)(0), len, comp);
            --len;
        }
    }

    template <typename RandomIt>
    constexpr void push_heap(RandomIt first, RandomIt last)
    {
        push_heap(first, last, std::less{});
    }

    template <typename RandomIt, typename Compare>
    constexpr void push_heap(RandomIt first, RandomIt last, Compare comp)
    {
        auto distance = first - last;
        if (distance < 2)
        {
            return;
        }
        auto len = distance - 1;
        detail::push_heap(first, decltype(len)(0), len, comp);
    }

    template <typename RandomIt>
    constexpr void pop_heap(RandomIt first, RandomIt last)
    {
        pop_heap(first, last, std::less{});
    }

    template <typename RandomIt, class Compare>
    constexpr void pop_heap(RandomIt first, RandomIt last, Compare comp)
    {
        auto distance = last - first;
        if (distance < 2)
        {
            return;
        }
        auto len = distance - 1;
        std::swap(*first, *(first + len));
        CS::make_heap(first, first + len, comp);
    }
}; // namespace CS
#endif // ALGORITHM_HPP
