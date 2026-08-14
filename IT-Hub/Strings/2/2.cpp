#include "../../../include/utils.h"
#include <iostream>
#include <utility>

using namespace std;

int getPalindromeLength(const string &s, int idx) {
  int len = s.length();
  // Odd Palindrome
  int m = 1;
  while (idx - m >= 0 && idx + m < len && s[idx - m] == s[idx + m])
    m++;
  m--;
  // Even Palindrome
  int n = 0;
  while (idx - n >= 0 && idx + n + 1 < len && s[idx - n] == s[idx + n + 1])
    n++;
  return max((2 * m + 1), 2 * n);
}

string longestPalindrome(const string &s) {
  pair<int, int> maxLen = {0, 0};
  for (int i = 0; i < s.length(); i++) {
    pair<int, int> curLen = {i, getPalindromeLength(s, i)};
    if (curLen.second > maxLen.second)
      maxLen = curLen;
  }
  return s.substr(maxLen.first - (maxLen.second - 1) / 2, maxLen.second);
}

int main() {
  printTitle("Longest Palindromic Substring");
  string solution = longestPalindrome("babad");
  cout << "Solution: " << solution << endl;
  return 0;
}
