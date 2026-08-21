#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

int recs(string &word1, string &word2, int idx1, int idx2,
         vector<vector<int>> &memo) {
  // base cases
  if (idx1 == word1.length())
    return word2.length() - idx2; // insertions needed
  if (idx2 == word2.length())
    return word1.length() - idx1; // deletions needed

  // reference to memo
  int &ans = memo[idx1][idx2];

  if (ans == -1) {
    if (word1[idx1] == word2[idx2])
      ans = recs(word1, word2, idx1 + 1, idx2 + 1, memo);
    else {
      int remove = recs(word1, word2, idx1 + 1, idx2, memo);
      int insert = recs(word1, word2, idx1, idx2 + 1, memo);
      int replace = recs(word1, word2, idx1 + 1, idx2 + 1, memo);
      ans = min({remove, insert, replace}) + 1;
    }
  }
  return ans;
}

int minDistance(string word1, string word2) {
  vector<vector<int>> memo(word1.length(), vector<int>(word2.length(), -1));
  return recs(word1, word2, 0, 0, memo);
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
