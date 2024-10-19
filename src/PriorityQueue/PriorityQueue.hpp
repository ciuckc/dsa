//
// Created by scristia on 18-10-24.
//

#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <utility>
#include <vector>

#include "Algorithm.hpp"

namespace CS
{
  template <typename T,
            typename Container = std::vector<T>,
            typename Compare = std::less<typename Container::value_type>>
  class PriorityQueue
  {
  public:
    using container_type = Container;
    using value_compare = Compare;
    using value_type = T;
    using size_type = typename Container::size_type;
    using const_reference = typename Container::const_reference;

    PriorityQueue() : _comp(), _container()
    {
    }

    PriorityQueue(const value_compare& comp, const container_type& container)
      : _comp(comp),
        _container(container)
    {
    }

    PriorityQueue(value_compare&& comp, container_type&& container)
      : _comp(std::exchange(comp, {})),
        _container(std::exchange(container, {}))
    {
    }

    PriorityQueue(const PriorityQueue&) = default;

    PriorityQueue(PriorityQueue&&) noexcept = default;

    ~PriorityQueue() = default;

    PriorityQueue& operator=(const PriorityQueue&) = default;

    PriorityQueue& operator=(PriorityQueue&&) noexcept = default;

    void pop()
    {
      _container.pop_back();
    }

    bool empty() const
    {
      return _container.empty();
    }

    void push(const value_type& value)
    {
      _container.push_back(value);
      CS::push_heap(_container.begin(), _container.end(), _comp);
    }

    void push(value_type&& value)
    {
      _container.push_back(std::move(value));
      CS::push_heap(_container.begin(), _container.end(), _comp);
    }

    const_reference top() const
    {
      return _container.front();
    }

  private:
    value_compare _comp;
    container_type _container;
  };
}
#endif //PRIORITYQUEUE_HPP
