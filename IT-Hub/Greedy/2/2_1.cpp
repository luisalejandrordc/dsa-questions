#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  for (int start = 0; start < gas.size(); start++) {
    int tank = 0, idx = start;
    while (true) {
      tank += gas[idx] - cost[idx];
      if (tank < 0)
        break;
      idx = idx == gas.size() - 1 ? 0 : idx + 1;
      if (idx == start)
        return start;
    }
  }
  return -1;
}

int main() {
  printTitle("Gas Station");
  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};
  int solution = timedCall(canCompleteCircuit, gas, cost);
  cout << "Solution: " << solution << endl;
  return 0;
}
