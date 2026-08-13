#pragma once
#include <iostream>
#include <string>

inline void printTitle(const std::string &title) {
  std::string border(title.length() + 10, '-');
  std::cout << border << std::endl;
  std::cout << "|    " << title << "    |" << std::endl;
  std::cout << border << std::endl;
}
