#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals) {
  vector<vector<int>> result;
  for (int i = 0; i < intervals.size(); i++) {
    int x1 = intervals[i][0], y1 = intervals[i][1];
    for (int j = i + 1; j < intervals.size(); j++) {
      int x2 = intervals[j][0], y2 = intervals[j][1];
      if ((x1 >= x2 && x1 <= y2) || (x2 >= x1 && x2 <= y1)) {
        // cout << "{" << x1 << ", " << y1 << "}\t";
        // cout << "{" << x2 << ", " << y2 << "}\t";
        intervals.erase(intervals.begin() + j);
        j = i; // reset for detecting possible new overlaps
        x1 = min(x1, x2);
        y1 = max(y1, y2);
        // cout << "{" << x1 << ", " << y1 << "}\n";
      }
    }
    result.push_back({x1, y1});
  }
  return result;
}

int main() {
  printTitle("Merge Intervals");
  // vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> intervals = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
  vector<vector<int>> solution = timedCall(mergeIntervals, intervals);
  cout << "Solution:" << endl;
  for (const auto &v : solution)
    printVector(v);
  return 0;
}
