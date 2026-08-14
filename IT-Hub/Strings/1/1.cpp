#include "../../../include/utils.h"
#include <iostream>
#include <unordered_map>

using namespace std;

bool bruteForce(string s, string t) {
  if (s.length() != t.length())
    return false;
  for (char c : s) {
    bool found = false;
    for (int i = 0; i < t.length(); i++)
      if (c == t[i]) {
        found = true;
        t.erase(i, 1);
        break;
      }
    if (!found)
      return false;
  }
  return true;
}

bool optimized(string s, string t) {
  if (s.length() != t.length())
    return false;
  unordered_map<char, int> letters;
  for (char c : s)
    letters[c]++;
  for (char c : t)
    if (!letters.count(c) || letters[c]-- == 0)
      return false;
  return true;
}

int main() {
  printTitle("Valid Anagram");
  string s = "anagram", t = "nagaram";
  string solution = optimized(s, t) ? "True" : "False";
  cout << "Solution: " << solution << endl;
  return 0;
}
