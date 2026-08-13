#include "../../../include/utils.h"
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

pair<int, int> brute_force(vector<int> &nums, int target) {
  int len = nums.size();
  for (int i = 0; i < len; i++)
    for (int j = i + 1; j < len; j++)
      if (nums[i] + nums[j] == target)
        return {i, j};
  return {-1, -1};
}

pair<int, int> optimized(vector<int> &nums, int target) {
  unordered_map<int, int> seen;
  int len = nums.size();
  for (int i = 0; i < len; i++) {
    int x = target - nums[i];
    if (seen.count(x))
      return {seen[x], i};
    seen[nums[i]] = i;
  }
  return {-1, -1};
}

int main() {
  printTitle("Two Sum");
  vector<int> nums = {1, 2, 3, 4, 5};
  int target = 9;
  pair<int, int> solution = optimized(nums, target);
  cout << "Solution: (" << solution.first << ", " << solution.second << ")"
       << endl;
  return 0;
}
