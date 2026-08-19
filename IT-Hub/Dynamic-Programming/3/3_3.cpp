#include "../../../include/utils.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int> &coins, int amount) {
  // dp[x] -> fewest coins needed to make up amount x
  vector<int> dp(amount + 1, amount + 1);
  dp[0] = 0;
  for (int x = 1; x <= amount; x++)
    for (const int coin : coins)
      if (x - coin >= 0)
        dp[x] = min(dp[x], dp[x - coin] + 1);
  return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int main() {
  printTitle("Coin Change");
  vector<int> coins{2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24};
  int amount = 9999;
  // vector<int> coins{474, 83, 404, 3};
  // int amount = 264;
  cout << "Solution: " << coinChange(coins, amount) << endl;
  timedCall(coinChange, coins, amount);
  return 0;
}
