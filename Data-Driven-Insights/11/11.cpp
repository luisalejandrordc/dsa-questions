#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int longestSubstring(string s) {
  int l = 0;
  int maxCount = 0;
  unordered_map<char, int> visited;
  for (int i = 0; i < s.length(); i++) {
    if (visited.count(s[i]) && visited[s[i]] >= l)
      l = visited[s[i]] + 1;
    visited[s[i]] = i;
    maxCount = max(maxCount, i + 1 - l);
  }
  return maxCount;
}

int main() {
  cout << "It's Showtime Folks!" << endl;
  cout << "Solution: " << longestSubstring("abcabcbb") << endl;
  cout << "Solution: " << longestSubstring("bbbbb") << endl;
  cout << "Solution: " << longestSubstring("pwwkew") << endl;
  return 0;
}
