#include "../../../include/utils.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int getMinLength(const vector<string> &strs) {
  int minLength = INT_MAX;
  for (const string &s : strs)
    minLength = min(minLength, int(s.length()));
  return minLength;
}

string longestCommonPrefix(vector<string> &strs) {
  if (strs.empty())
    return "";
  int minLength = getMinLength(strs);
  for (int i = 0; i < minLength; i++)
    for (int j = 1; j < strs.size(); j++)
      if (strs[0][i] != strs[j][i])
        return strs[0].substr(0, i);
  return strs[0].substr(0, minLength);
}

int main() {
  printTitle("Longest Common Prefix");
  vector<string> strs = {"flower", "flow", "flight"};
  cout << "Solution: " << longestCommonPrefix(strs) << endl;
}
