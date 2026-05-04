#include <iostream>

using namespace std;

string getOddPalindrome(string s, int idx) {
  int n = 1;
  int len = s.length();
  while (idx - n >= 0 && idx + n < len && s[idx - n] == s[idx + n])
    n++;
  n--;
  return s.substr(idx - n, 2 * n + 1);
}

string getEvenPalindrome(string s, int idx) {
  int n = 0;
  int len = s.length();
  while (idx - n >= 0 && idx + 1 + n < len && s[idx - n] == s[idx + 1 + n])
    n++;
  n--;
  return n >= 0 ? s.substr(idx - n, 2 * (n + 1)) : "";
}

// A palindrome is a word or phrase that reads the same backward as forward
string longestPalindrome(string s) {
  string pal = "";
  // If the remaining characters can't beat my current best palindrome, stop
  // early
  for (int i = 0; i < s.length() - (pal.length() + 1) / 2; i++) {
    string even = getEvenPalindrome(s, i);
    string odd = getOddPalindrome(s, i);
    string longest = even.length() > odd.length() ? even : odd;
    if (longest.length() > pal.length())
      pal = longest;
  }
  return pal;
}

int main() {
  cout << "It's Showtime Folks!" << endl;
  cout << "Solution: " << longestPalindrome("babad") << endl;
  cout << "Solution: " << longestPalindrome("cbbd") << endl;
  return 0;
}
