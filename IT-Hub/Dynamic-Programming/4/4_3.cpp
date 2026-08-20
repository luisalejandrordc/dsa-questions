#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int> &nums) {
  vector<int> dp(nums.size() + 1, 0);
  // dp[idx] = length of the LIS that can be formed from
  // nums[idx], considering that nums[idx-1] is also part
  // of the subsequence
  for (int idx = nums.size() - 1; idx >= 0; idx--)
    for (int x = idx; x < nums.size(); x++)
      if (idx == 0 || nums[x] > nums[idx - 1])
        dp[idx] = max(dp[idx], dp[x + 1] + 1);
  // printVector(dp);
  return dp[0];
}

int main() {
  printTitle("Longest Increasing Subsequence");
  vector<int> nums = {0, 1, 0, 3, 2, 3};
  // vector<int> nums = {1, 2, 3, 4, 5, 6};
  // vector<int> nums;
  // for (int i = 0; i < 30; i++)
  //   nums.push_back(i + 1);
  printVector(nums);
  int solution = timedCall(lengthOfLIS, nums);
  cout << "Solution: " << solution << endl;
  return 0;
}
