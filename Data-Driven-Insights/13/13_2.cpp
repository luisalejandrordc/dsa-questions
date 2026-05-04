#include <iostream>
#include <utility>

using namespace std;

pair<int, int> getOddPalindrome(const string &s, const int &idx) {
  int n = 1;
  int len = s.length();
  while (idx - n >= 0 && idx + n < len && s[idx - n] == s[idx + n])
    n++;
  n--;
  return {idx - n, 2 * n + 1};
}

pair<int, int> getEvenPalindrome(const string &s, const int &idx) {
  int n = 0;
  int len = s.length();
  while (idx - n >= 0 && idx + 1 + n < len && s[idx - n] == s[idx + 1 + n])
    n++;
  n--;
  return {idx - n, 2 * (n + 1)};
}

// A palindrome is a word or phrase that reads the same backward as forward
string longestPalindrome(string s) {
  pair<int, int> pal = {0, 0}; // {idx, length}
  // If the remaining characters can't beat my current best palindrome, stop
  // early
  for (int i = 0; i < s.length() - (pal.second + 1) / 2; i++) {
    pair<int, int> even = getEvenPalindrome(s, i);
    pair<int, int> odd = getOddPalindrome(s, i);
    pair<int, int> longest = even.second > odd.second ? even : odd;
    if (longest.second > pal.second)
      pal = longest;
  }
  return s.substr(pal.first, pal.second);
}

int main() {
  cout << "It's Showtime Folks!" << endl;
  cout << "Solution: " << longestPalindrome("babad") << endl;
  cout << "Solution: " << longestPalindrome("cbbd") << endl;
  return 0;
}
