#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums) {
  int blockedDistance = 0;
  for (int i = nums.size() - 2; i >= 0; i--)
    if (nums[i] <= blockedDistance)
      blockedDistance++;
    else
      blockedDistance = 0;
  return blockedDistance == 0 ? true : false;
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
