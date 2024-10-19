//
// Created by scristia on 18-10-24.
//
#include "BinaryArray.hpp"

#include <complex>

BinaryArray::BinaryArray(const std::vector<int> &nums)
: _binary_array(static_cast<size_t>(std::pow(2uz, nums.size()) - 1))
{
  for (const auto num : nums)
  {
    insert(num);
  }
}

void BinaryArray::insert(int num)
{
  for (auto i = 0uz; i < _binary_array.size();)
  {
    if (!_binary_array[i].has_value())
    {
      _binary_array[i].emplace(num);
      break;
    }
    if (_binary_array[i].value() < num)
    {
      i = 2 * i + 2;
    }
    else
    {
      i = 2 * i + 1;
    }
  }
}

bool BinaryArray::find(const int num) const
{
  for (auto i = 0uz; i < _binary_array.size();)
  {
    if (!_binary_array[i].has_value())
    {
      return false;
    }
    if (_binary_array[i].value() == num)
    {
      return true;
    }
    if (_binary_array[i].value() < num)
      i = i * 2 + 2;
    else
      i = i * 2 + 1;
  }
  return false;
}
