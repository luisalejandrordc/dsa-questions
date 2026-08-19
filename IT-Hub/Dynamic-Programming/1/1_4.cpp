#include "../../../include/utils.h"
#include <iostream>

using namespace std;

// Bottom-Up solution (tabulation)
int climbStairs(int n) {
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++)
    dp[i] = dp[i - 1] + dp[i - 2];
  return dp[n];
}

int main() {
  printTitle("Climbing Stairs");
  for (int i = 1; i <= 10; i++)
    cout << "For n = " << i << " -> " << climbStairs(i) << endl;
  return 0;
}
