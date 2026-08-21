#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  int start = 0, tank = 0;
  int cumSum = 0;
  for (int i = 0; i < gas.size(); i++) {
    tank += gas[i] - cost[i];
    cumSum += gas[i] - cost[i];
    if (tank < 0) {
      start = i + 1;
      tank = 0;
    }
  }
  return cumSum < 0 ? -1 : start;
}

int main() {
  printTitle("Gas Station");
  // vector<int> gas = {1, 2, 3, 4, 5};
  // vector<int> cost = {3, 4, 5, 1, 2};
  vector<int> gas(1000, 0);
  gas.back() = 2;
  vector<int> cost(1000, 0);
  cost[998] = 1;
  printVector(cost);
  int solution = timedCall(canCompleteCircuit, gas, cost);
  cout << "Solution: " << solution << endl;
  return 0;
}
