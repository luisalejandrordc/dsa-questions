#include "../../../include/utils.h"
#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int recs(vector<int> &coins, int idx, int amount,
         unordered_map<pair<int, int>, int> &history) {
  // You can make up the amount by using only coins[idx]
  int quantity = amount / coins[idx];
  int remaining = amount - quantity * coins[idx];
  if (remaining == 0) {
    cout << "Coin: " << coins[idx] << "\t"
         << "Quantity: " << amount / coins[idx] << "\t END" << endl;
    return quantity;
  }
  // You need coins of different denominations, but already reached the end
  if (idx == coins.size() - 1)
    return -1;
  // Find a way to make up the amount using remaining denominations
  int result = INT_MAX;
  while (quantity >= 0) {
    pair<int, int> next = {idx + 1, remaining};
    if (!history.count(next))
      history[next] = recs(coins, next.first, next.second, history);
    if (history.at(next) != -1) {
      result = min(result, history.at(next) + quantity);
      cout << "Coin: " << coins[idx] << "\t" << "Quantity: " << quantity
           << endl;
    }
    remaining -= coins[idx];
    quantity--;
  }
  // Couldn't make up the the amount
  return result == INT_MAX ? -1 : result;
}

int coinChange(vector<int> &coins, int amount) {
  sort(coins.begin(), coins.end(), greater<int>());
  // key: <idx, amount> , value: <result>
  unordered_map<pair<int, int>, int> history;
  return recs(coins, 0, amount, history);
}

// This greedy solution has a problem: using as many of the largest coin
// as possible does not mean you'll get the most optimal result (minimum)
// Example: coins = {4, 3, 1}, amount = 6 -> Expected result = 2
int recs2(vector<int> &coins, int idx, int amount) {
  // You can make up the amount using only coins of denomination coins[idx]
  if (amount % coins[idx] == 0)
    return amount / coins[idx];
  // You need coins of different denominations, but already reached the end
  if (idx == coins.size() - 1)
    return -1;
  // Find a way to make up the amount using remaining denominations
  for (int q = amount / coins[idx]; q >= 0; q--) {
    int counter = recs2(coins, amount - q * coins[idx], idx + 1);
    if (counter != -1)
      return counter + q;
  }
  // Couldn't make up the the amount
  return -1;
}

int main() {
  printTitle("Coin Change");
  vector<int> coins = {186, 419, 83, 408};
  int amount = 6249;
  // vector<int> coins = {4, 3, 1};
  // int amount = 6;
  cout << "Solution: " << coinChange(coins, amount) << endl;
  return 0;
}
