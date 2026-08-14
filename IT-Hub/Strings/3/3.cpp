#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  vector<vector<string>> v;
  return v;
}

int main() {
  printTitle("Group Anagrams");
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> solution = groupAnagrams(strs);
  cout << "Solution: ";
  for (auto v : groupAnagrams(strs))
    printVector(v);
  return 0;
}
