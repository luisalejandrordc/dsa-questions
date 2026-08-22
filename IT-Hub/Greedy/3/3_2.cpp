#include "../../../include/utils.h"
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void sortIntervals(vector<vector<int>> &intervals) {
  int i = 1;
  while (i < intervals.size()) {
    if (intervals[i - 1][0] > intervals[i][0]) {
      swap(intervals[i - 1][0], intervals[i][0]);
      swap(intervals[i - 1][1], intervals[i][1]);
      i = i > 1 ? i - 1 : i + 1;
    } else
      i++;
  }
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals) {
  sortIntervals(intervals);
  vector<vector<int>> result;
  int x1, y1, x2, y2;
  bool merged = false;
  for (int i = 0; i < intervals.size(); i++) {
    if (!merged) {
      x1 = intervals[i][0];
      y1 = intervals[i][1];
    }
    if (i + 1 == intervals.size()) {
      result.push_back({x1, y1});
      break;
    }
    x2 = intervals[i + 1][0];
    y2 = intervals[i + 1][1];
    if (x2 <= y1) {
      x1 = min(x1, x2);
      y1 = max(y1, y2);
      merged = true;
    } else {
      merged = false;
      result.push_back({x1, y1});
    }
  }
  return result;
}

int main() {
  printTitle("Merge Intervals");
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  // vector<vector<int>> intervals = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
  vector<vector<int>> solution = timedCall(mergeIntervals, intervals);
  cout << "Solution:" << endl;
  for (const auto &v : solution)
    printVector(v);
  return 0;
}
