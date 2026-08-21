#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

string largestSubsequence(string word1, string word2) {
  int length2 = word2.length();
  int maxLength = 0, start = 0;
  for (int i = 0; i < length2; i++) {
    int idx = i;
    for (const char &c : word1) {
      if (c == word2[idx])
        idx++;
      if (idx == length2)
        break;
    }
    if (idx - i > maxLength) {
      maxLength = idx - i;
      start = i;
    }
    // Already found the maximum possible length
    if (maxLength >= length2 - (i + 1))
      break;
  }
  return word2.substr(start, maxLength);
}

int minDistance(string word1, string word2) {
  int result = 0;
  cout << largestSubsequence(word1, word2) << endl;
  return result;
}

int main() {
  printTitle("Edit Distance");
  // string word1 = "horse", word2 = "ros";
  // string word1 = "intention", word2 = "execution";
  string word1 = "dinitrophenylhydrazine", word2 = "acetylphenylhydrazine";
  int solution = timedCall(minDistance, word1, word2);
  cout << "Solution: " << solution << endl;
  return 0;
}
