#include "../../../include/utils.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals) {
  sort(intervals.begin(), intervals.end(),
       [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

  int erased = 0;
  int lastEnd = intervals[0][1];
  for (int i = 1; i < intervals.size(); i++)
    if (intervals[i][0] < lastEnd) {
      lastEnd = min(lastEnd, intervals[i][1]);
      erased++;
    } else
      lastEnd = intervals[i][1];

  return erased;
}

// same algorithm, plus printing the final intervals
int eraseOverlapIntervals1(vector<vector<int>> &intervals) {
  sort(intervals.begin(), intervals.end(),
       [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

  int erased = 0;
  vector<int> lastInterval = intervals[0];
  vector<vector<int>> finalIntervals;
  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] < lastInterval[1]) {
      if (intervals[i][1] < lastInterval[1])
        lastInterval = intervals[i];
      erased++;
    } else {
      finalIntervals.push_back(lastInterval);
      lastInterval = intervals[i];
    }
    if (i == intervals.size() - 1)
      finalIntervals.push_back(lastInterval);
  }

  for (const auto &v : finalIntervals)
    printVector(v);

  return erased;
}

int main() {
  printTitle("Non-overlapping Intervals");
  // vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  vector<vector<int>> intervals = {
      {-24, 99},  {96, 98},   {71, 96},  {88, 99}, {-24, 4},  {99, 100},
      {-69, -27}, {18, 28},   {25, 38},  {8, 25},  {-99, 33}, {-85, -30},
      {56, 64},   {-77, 98},  {-38, 88}, {-96, 6}, {91, 92},  {-39, 80},
      {-7, 97},   {-82, 9},   {-80, 3},  {87, 94}, {-96, 16}, {-15, 40},
      {-40, 86},  {31, 81},   {97, 98},  {69, 83}, {-40, 47}, {1, 82},
      {13, 44},   {-92, -65}, {51, 80}};
  int solution = timedCall(eraseOverlapIntervals1, intervals);
  cout << "Solution: " << solution << endl;
  return 0;
}
