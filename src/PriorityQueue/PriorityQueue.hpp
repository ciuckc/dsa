//
// Created by scristia on 18-10-24.
//

#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <functional>
#include <vector>

#include "../Algorithm/Algorithm.hpp"

namespace CS
{
template <typename T, typename Container = std::vector<T>, typename Compare = std::less<typename Container::value_type>>
class PriorityQueue {
public:
  using container_type = Container;
  using value_compare = Compare;
  using value_type = T;
  using size_type = Container::size_type;
  using const_reference = Container::const_reference;

  void push(const value_type &value)
  {
    _container.push_back(value);
    CS::make_heap(_container.begin(), _container.end(), value_compare{});
  }

  void print_queue() const
  {
    for (const auto& element : _container)
    {
      std::cout << element << ' ';
    }
  }

private:
  Container _container;
};
}
#endif //PRIORITYQUEUE_HPP
