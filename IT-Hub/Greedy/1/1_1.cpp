#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

// top-down algorithm
bool recs(vector<int> &nums, int idx, vector<bool> &memo) {
  // base case
  if (idx == nums.size() - 1)
    return true;
  // recurrence
  if (memo[idx] == false)
    return false;
  else
    for (int x = min(nums[idx], int(nums.size()) - idx - 1); x > 0; x--)
      if (recs(nums, idx + x, memo))
        return true;
  return memo[idx] = false;
}

bool canJump(vector<int> &nums) {
  // memo[idx] = true -> not computed yet
  vector<bool> memo(nums.size(), true);
  return recs(nums, 0, memo);
}

int main() {
  printTitle("Jump Game");
  // vector<int> nums = {2, 3, 1, 1, 4};
  // vector<int> nums = {3, 2, 1, 0, 4};
  vector<int> nums(9999);
  for (int i = 0; i < 9999; i++)
    nums[i] = 9997 - i;
  string solution = timedCall(canJump, nums) ? "True" : "False";
  cout << "Solution: " << solution << endl;
  return 0;
}
