#include "../../../include/utils.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

// highly inefficient in memory and execution time, but ...
// it works at least xd
int getMinErases(const vector<int> &overlaps,
                 const vector<pair<int, int>> &overIndices, int idx) {
  // base cases
  if (accumulate(overlaps.begin(), overlaps.end(), 0) == 0)
    return 0;
  if (idx == overlaps.size())
    return INT_MAX;

  // don't erase idx
  int dontErase = getMinErases(overlaps, overIndices, idx + 1);

  // erase idx
  vector<int> newOverlaps = overlaps;
  vector<pair<int, int>> newOverIndices;
  for (auto p : overIndices)
    if (p.first == idx || p.second == idx) {
      newOverlaps[p.first]--;
      newOverlaps[p.second]--;
    } else
      newOverIndices.push_back(p);
  int erase = getMinErases(newOverlaps, newOverIndices, idx + 1);
  if (erase != INT_MAX)
    erase++;

  return min(erase, dontErase);
}

int eraseOverlapIntervals(vector<vector<int>> &intervals) {
  sort(intervals.begin(), intervals.end(),
       [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

  vector<int> overlaps(intervals.size(), 0);
  vector<pair<int, int>> overIndices;
  int counter = 0;
  for (int i = 0; i < intervals.size() - 1; i++)
    for (int j = i + 1; j < intervals.size(); j++)
      if (intervals[j][0] < intervals[i][1]) {
        counter += 2;
        overlaps[i]++;
        overlaps[j]++;
        overIndices.push_back({i, j});
      }

  return getMinErases(overlaps, overIndices, 0);
}

// "remove the interval that overlaps with most others"
// good idea, but not correct
int eraseOverlapIntervals1(vector<vector<int>> &intervals) {
  sort(intervals.begin(), intervals.end(),
       [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

  vector<int> overlaps(intervals.size(), 0);
  vector<pair<int, int>> overIndices;
  int counter = 0;
  for (int i = 0; i < intervals.size() - 1; i++)
    for (int j = i + 1; j < intervals.size(); j++)
      if (intervals[j][0] < intervals[i][1]) {
        counter += 2;
        overlaps[i]++;
        overlaps[j]++;
        overIndices.push_back({i, j});
      }

  int deletions = 0;
  while (counter != 0) {
    auto max_it = max_element(overlaps.begin(), overlaps.end());
    int max_idx = distance(overlaps.begin(), max_it);
    counter -= 2 * overlaps[max_idx];
    deletions++;
    for (auto it = overIndices.begin(); it != overIndices.end();) {
      if (it->first == max_idx || it->second == max_idx) {
        overlaps[it->first]--;
        overlaps[it->second]--;
        it = overIndices.erase(it);
      } else
        it++;
    }
  }

  return deletions;
}

int main() {
  printTitle("Non-overlapping Intervals");
  // vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  vector<vector<int>> intervals = {{0, 2}, {1, 3}, {1, 3}, {2, 4},
                                   {3, 5}, {3, 5}, {4, 6}};
  int solution = timedCall(eraseOverlapIntervals, intervals);
  cout << "Solution: " << solution << endl;
  return 0;
}
