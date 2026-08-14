#include "../../../include/utils.h"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char, int> stringToMap(const string &s) {
  unordered_map<char, int> letters;
  for (const char &c : s)
    letters[c]++;
  return letters;
}

bool isAnagram(unordered_map<char, int> &s, unordered_map<char, int> &t) {
  for (const auto &item : s)
    if (!t.count(item.first) || item.second != t[item.first])
      return false;
  return true;
}

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  vector<vector<string>> anagrams;
  int size = strs.size();

  vector<unordered_map<char, int>> letters;
  letters.reserve(size);
  for (const string &s : strs)
    letters.push_back(stringToMap(s));

  vector<pair<int, int>> lengths;
  lengths.reserve(size);
  for (int i = 0; i < size; i++)
    lengths.push_back({i, strs[i].length()});

  while (!lengths.empty()) {
    vector<string> v = {strs[lengths[0].first]};
    int i = 1;
    while (i < lengths.size())
      if (lengths[0].second == lengths[i].second &&
          isAnagram(letters[lengths[0].first], letters[lengths[i].first])) {
        v.push_back(strs[lengths[i].first]);
        lengths.erase(lengths.begin() + i);
      } else
        i++;
    lengths.erase(lengths.begin());
    anagrams.push_back(v);
  }
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
