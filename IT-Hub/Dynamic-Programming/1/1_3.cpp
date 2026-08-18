#include "../../../include/utils.h"
#include <iostream>
#include <unordered_map>

using namespace std;

int recs(int n, unordered_map<int, int> &history) {
  if (n == 0) // Top reached
    return 1;
  if (n < 0) // Top exceeded
    return 0;
  if (!history.count(n - 1))
    history[n - 1] = recs(n - 1, history);
  if (!history.count(n - 2))
    history[n - 2] = recs(n - 2, history);
  return history.at(n - 1) + history.at(n - 2);
}

int climbStairs(int n) {
  unordered_map<int, int> history;
  return recs(n, history);
}

int main() {
  printTitle("Climbing Stairs");
  for (int i = 1; i <= 45; i++)
    cout << "For n = " << i << " -> " << climbStairs(i) << endl;
  return 0;
}
