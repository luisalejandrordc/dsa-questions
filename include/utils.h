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
  std::cout << "[\t";
  for (const int x : nums)
    std::cout << x << "\t";
  std::cout << "]" << std::endl;
}
