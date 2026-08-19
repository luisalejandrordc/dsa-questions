#include "../../../include/utils.h"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int recs(vector<int> &nums, int idx, unordered_map<int, int> &memo) {
  if (idx == nums.size() - 1)
    return 0;
  int maxLength = 0;
  for (int i = idx + 1; i < nums.size(); i++)
    if (idx == -1 || nums[idx] < nums[i]) {
      if (!memo.count(i))
        memo[i] = recs(nums, i, memo);
      maxLength = max(maxLength, memo.at(i) + 1);
    }
  return maxLength;
}

int lengthOfLIS(vector<int> &nums) {
  unordered_map<int, int> memo;
  // idx -> last element of the subsequence
  return recs(nums, -1, memo); // -1 means no element
}

// Correct, but inefficient
// It takes too much time to execute without memoization
int recs2(vector<int> &nums, int idx) {
  if (idx == nums.size() - 1)
    return 0;
  int maxLength = 0;
  for (int i = idx + 1; i < nums.size(); i++)
    if (idx == -1 || nums[idx] < nums[i])
      maxLength = max(maxLength, recs2(nums, i) + 1);
  return maxLength;
}

int lengthOfLIS2(vector<int> &nums) { return recs2(nums, -1); }

// This solution creates new arrays for each recursive call
// using a LOT of memory and taking a LOT of execution time
int lengthOfLIS1(vector<int> &nums) {
  if (nums.empty())
    return 0;
  int result = 1;
  for (int i = 0; i < nums.size(); i++) {
    vector<int> remaining;
    for (int j = i + 1; j < nums.size(); j++)
      if (nums[i] < nums[j])
        remaining.push_back(nums[j]);
    result = max(result, lengthOfLIS1(remaining) + 1);
  }
  return result;
}

int main() {
  printTitle("Longest Increasing Subsequence");
  // vector<int> nums = {0, 1, 0, 3, 2, 3};
  // vector<int> nums = {1, 2, 3, 4, 5, 6};
  vector<int> nums;
  for (int i = 0; i < 30; i++)
    nums.push_back(i + 1);
  printVector(nums);
  int solution = timedCall(lengthOfLIS, nums);
  // int solution = timedCall(lengthOfLIS2, nums);
  cout << "Solution: " << solution << endl;
  return 0;
}
