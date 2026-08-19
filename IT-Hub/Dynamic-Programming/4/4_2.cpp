#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

int recs(vector<int> &nums, int idx, vector<int> &memo) {
  if (idx == nums.size())
    return 0;
  int maxLength = 0;
  for (int i = idx; i < nums.size(); i++)
    if (idx == 0 || nums[i] > nums[idx - 1]) {
      if (memo[i + 1] == -1)
        memo[i + 1] = recs(nums, i + 1, memo);
      maxLength = max(maxLength, memo[i + 1] + 1);
    }
  return maxLength;
}

int lengthOfLIS(vector<int> &nums) {
  vector<int> memo(nums.size() + 1, -1);
  // memo[idx] = length of the longest increasing subsequence
  // that can be formed from nums[idx]
  return recs(nums, 0, memo);
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
  cout << "Solution: " << solution << endl;
  return 0;
}
