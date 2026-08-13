#pragma once
#include <iostream>
#include <string>
#include <vector>

inline void printTitle(const std::string &title) {
  std::string border(title.length() + 10, '-');
  std::cout << border << std::endl;
  std::cout << "|    " << title << "    |" << std::endl;
  std::cout << border << std::endl;
}

inline void printVector(const std::vector<int> &nums) {
  if (nums.empty()) {
    std::cout << "[]" << std::endl;
    return;
  }
  int len = nums.size();
  std::cout << "[";
  for (int i = 0; i < len - 1; i++) {
    std::cout << nums[i] << ", ";
  }
  std::cout << nums[len - 1] << "]" << std::endl;
}
