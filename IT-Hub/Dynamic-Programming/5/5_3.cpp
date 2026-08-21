#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

// bottom-up solution using tabulation
int minDistance(string word1, string word2) {
  // variables
  int m = word1.length(), n = word2.length();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1));

  // base cases
  for (int i = 0; i <= m; i++)
    dp[i][n] = m - i; // deletions
  for (int j = 0; j <= n; j++)
    dp[m][j] = n - j; // insertions

  // filling backwards
  for (int i = m - 1; i >= 0; i--)
    for (int j = n - 1; j >= 0; j--)
      if (word1[i] == word2[j])
        dp[i][j] = dp[i + 1][j + 1];
      else
        dp[i][j] = 1 + min({
                           dp[i + 1][j],     // delete
                           dp[i][j + 1],     // insert
                           dp[i + 1][j + 1], // replace
                       });

  return dp[0][0];
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
