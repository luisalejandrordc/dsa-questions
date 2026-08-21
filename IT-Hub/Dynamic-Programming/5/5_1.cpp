#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

int minResult(vector<int> &results) {
  int minValue = results[0];
  for (int i = 1; i < results.size(); i++)
    minValue = min(minValue, results[i]);
  return minValue;
}

int recs(string &word1, string &word2, int idx1, int idx2,
         vector<vector<int>> &memo) {
  // base cases
  if (idx1 == word1.length())
    return word2.length() - idx2; // insertions needed
  if (idx2 == word2.length())
    return word1.length() - idx1; // deletions needed

  if (word1[idx1] == word2[idx2]) {
    // match
    if (memo[idx1 + 1][idx2 + 1] == -1)
      memo[idx1 + 1][idx2 + 1] = recs(word1, word2, idx1 + 1, idx2 + 1, memo);
    return memo[idx1 + 1][idx2 + 1];
  } else {
    // remove
    if (memo[idx1 + 1][idx2] == -1)
      memo[idx1 + 1][idx2] = recs(word1, word2, idx1 + 1, idx2, memo);
    // insert
    if (memo[idx1][idx2 + 1] == -1)
      memo[idx1][idx2 + 1] = recs(word1, word2, idx1, idx2 + 1, memo);
    // replace
    if (memo[idx1 + 1][idx2 + 1] == -1)
      memo[idx1 + 1][idx2 + 1] = recs(word1, word2, idx1 + 1, idx2 + 1, memo);
    // results
    vector<int> results = {
        memo[idx1 + 1][idx2],
        memo[idx1][idx2 + 1],
        memo[idx1 + 1][idx2 + 1],
    };
    return minResult(results) + 1;
  }
}

int minDistance(string word1, string word2) {
  vector<vector<int>> memo(word1.length() + 1,
                           vector<int>(word2.length() + 1, -1));
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
