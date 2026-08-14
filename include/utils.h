#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

inline void printTitle(const std::string &title) {
  std::string border(title.length() + 10, '-');
  std::cout << border << std::endl;
  std::cout << "|    " << title << "    |" << std::endl;
  std::cout << border << std::endl;
}

template <typename T> inline void printVector(const std::vector<T> &vec) {
  std::cout << "[";
  for (int i = 0; i < vec.size(); i++) {
    if (i > 0)
      std::cout << ", ";
    std::cout << vec[i];
  }
  std::cout << "]" << std::endl;
}

template <typename K, typename V>
inline void printMap(const std::unordered_map<K, V> &map) {
  std::cout << "{";
  int i = 0;
  for (auto &item : map) {
    if (i > 0)
      std::cout << ", ";
    std::cout << item.first << ": " << item.second;
    i++;
  }
  std::cout << "}" << std::endl;
}
