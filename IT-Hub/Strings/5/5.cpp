#include "../../../include/utils.h"
#include <iostream>
#include <unordered_map>

using namespace std;

const unordered_map<char, int> ROMANS = {
    {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000},
};

int romanToInt(string s) {
  int num = 0, len = s.length();
  for (int i = 0; i < len; i++)
    if (i + 1 < len && ROMANS.at(s[i]) < ROMANS.at(s[i + 1])) {
      num += ROMANS.at(s[i + 1]) - ROMANS.at(s[i]);
      i++;
    } else
      num += ROMANS.at(s[i]);
  return num;
}

int main() {
  printTitle("Roman to Integer");
  cout << "Solution: " << romanToInt("MCMXCIV") << endl;
  return 0;
}
