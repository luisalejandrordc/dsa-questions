#include "../../../include/utils.h"
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

string sortString(string s) {
  int idx = 1;
  while (idx < s.length())
    if (s[idx] < s[idx - 1]) {
      swap(s[idx], s[idx - 1]);
      idx = max(1, idx - 1);
    } else
      idx++;
  return s;
}

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  unordered_map<string, vector<string>> groups;
  for (const string &s : strs) {
    // string key = s;
    // sort(key.begin(), key.end());
    string key = sortString(s);
    groups[key].push_back(s);
  }
  vector<vector<string>> anagrams;
  for (const auto &item : groups)
    anagrams.push_back(item.second);
  // Print Groups with Keys
  // for (const auto &item : groups) {
  //   cout << item.first << ": {";
  //   for (int i = 0; i < item.second.size(); i++) {
  //     if (i > 0)
  //       cout << ", ";
  //     cout << item.second[i];
  //   }
  //   cout << "}" << endl;
  // }
  return anagrams;
}

int main() {
  printTitle("Group Anagrams");
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  cout << "Solution:" << endl;
  for (const vector<string> &v : groupAnagrams(strs))
    printVector(v);
  return 0;
}
