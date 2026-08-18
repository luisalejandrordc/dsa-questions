#include "../../../include/utils.h"
#include <chrono>
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
  auto start = chrono::steady_clock::now();
  for (int i = 1; i <= 45; i++)
    cout << "For n = " << i << " -> " << climbStairs(i) << endl;
  auto end = chrono::steady_clock::now();
  auto elapsed = chrono::duration<double>(end - start).count();
  cout << "Elapsed time: " << elapsed << " ms" << endl;
  timedCall(climbStairs, 45);
  return 0;
}
