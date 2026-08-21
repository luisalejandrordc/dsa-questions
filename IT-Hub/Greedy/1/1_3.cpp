#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums) {
  int largestJump = 0;
  for (int i = 0; i < nums.size() - 1; i++) {
    largestJump = max(largestJump, nums[i]);
    if (largestJump == 0)
      return false;
    largestJump--;
  }
  return true;
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
