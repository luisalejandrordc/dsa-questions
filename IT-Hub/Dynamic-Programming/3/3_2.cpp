#include "../../../include/utils.h"
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int recs(vector<int> &coins, int amount, unordered_map<int, int> &history) {
  if (amount == 0)
    return 0;
  int result = INT_MAX, remainder;
  for (const int coin : coins) {
    remainder = amount - coin;
    if (remainder < 0)
      break;
    if (!history.count(remainder))
      history[remainder] = recs(coins, remainder, history);
    if (history[remainder] != -1)
      result = min(result, history[remainder] + 1);
  }
  return result == INT_MAX ? -1 : result;
}

int coinChange(vector<int> &coins, int amount) {
  unordered_map<int, int> history;
  sort(coins.begin(), coins.end());
  return recs(coins, amount, history);
}

int main() {
  printTitle("Coin Change");
  // vector<int> coins{2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24};
  // int amount = 9999;
  vector<int> coins{474, 83, 404, 3};
  int amount = 264;
  cout << "Solution: " << coinChange(coins, amount) << endl;
  timedCall(coinChange, coins, amount);
  return 0;
}
