//
// Created by scristia on 18-10-24.
//

#ifndef BINARYARRAY_HPP
# define BINARYARRAY_HPP

#include <optional>
#include <vector>

/// The root of a binary tree starts at position 0
/// 
/// To get the parent of a node at position i -> (i / 2) - 1
/// To get the left child of a node at position i -> 2 * i + 1
/// To get the right child of a node at position i -> 2 * i + 2
/// 
/// Size of the binary tree array has to be at least 2 ^ n - 1,
///   where n is the number of elements. [ S = 2^n - 1 ]. Worst case!
///
/// If tree is complete, the formula becomes [ S = 2^(log2 n) - 1 ]
///
/// The max number of nodes at a given level is 2 ^ M, where m is the current level
///
/// To get the current depth at position i, we do log2 (i + 1)
class BinaryArray {
public:
  explicit BinaryArray(const std::vector<int> &nums);

  void insert(int num);

  bool find(const int num) const;

private:
  std::vector<std::optional<int>> _binary_array{};
};
#endif //BINARYARRAY_HPP
