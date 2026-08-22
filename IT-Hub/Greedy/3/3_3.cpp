#include "../../../include/utils.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals) {
  if (intervals.empty())
    return {};

  sort(intervals.begin(), intervals.end(),
       [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

  vector<vector<int>> result;
  result.push_back(intervals[0]);
  for (int i = 1; i < intervals.size(); i++) {
    vector<int> &a = result.back();
    const vector<int> &b = intervals[i];
    if (b[0] <= a[1])
      a = {min(a[0], b[0]), max(a[1], b[1])};
    else
      result.push_back(b);
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
