#include "../../../include/utils.h"
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int brute_force(vector<int> &nums) {
  int len = nums.size();
  int maxSum = INT_MIN;
  for (int l = 0; l < len; l++) {
    int curSum = 0;
    for (int r = l; r < len; r++) {
      curSum += nums[r];
      maxSum = max(maxSum, curSum);
    }
  }
  return maxSum;
}

int optimized(vector<int> &nums) {
  int maxSum = nums[0], curSum = nums[0];
  for (int r = 1; r < nums.size(); r++) {
    curSum = curSum <= 0 ? nums[r] : curSum += nums[r];
    maxSum = max(maxSum, curSum);
  }
  return maxSum;
}

vector<int> optimized_vector(vector<int> &nums) {
  int maxSum = nums[0], curSum = nums[0];
  int l = 0, left = 0, right = 0;
  for (int r = 1; r < nums.size(); r++) {
    if (curSum <= 0) {
      curSum = nums[r];
      l = r;
    } else
      curSum += nums[r];
    if (curSum > maxSum) {
      maxSum = curSum;
      left = l;
      right = r;
    }
  }
  return vector<int>(nums.begin() + left, nums.begin() + right + 1);
}

int main() {
  printTitle("Maximum Subarray");
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << "Solution: " << optimized(nums) << endl;
  cout << "Array: ";
  printVector(optimized_vector(nums));
  return 0;
}
