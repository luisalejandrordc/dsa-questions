#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  pair<int, int> minCumSum = {0, 0}; // {idx, num}
  int cumSum = 0;
  for (int i = 0; i < gas.size(); i++) {
    cumSum += gas[i] - cost[i];
    if (cumSum < minCumSum.second)
      minCumSum = {i + 1, cumSum};
  }
  return cumSum < 0 ? -1 : minCumSum.first;
}

int main() {
  printTitle("Gas Station");
  // vector<int> gas = {1, 2, 3, 4, 5};
  // vector<int> cost = {3, 4, 5, 1, 2};
  vector<int> gas(1000, 0);
  gas.back() = 2;
  vector<int> cost(1000, 0);
  cost[998] = 1;
  int solution = timedCall(canCompleteCircuit, gas, cost);
  cout << "Solution: " << solution << endl;
  return 0;
}
