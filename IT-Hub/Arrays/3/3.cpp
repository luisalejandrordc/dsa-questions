#include "../../../include/utils.h"
#include <iostream>
#include <utility>

using namespace std;

void brutal_force(vector<int> &nums) {
  int len = nums.size();
  if (len == 0)
    return;
  for (int i = 1; i < len; i++) {
    if (i != 0 && nums[i - 1] == 0 && nums[i] != 0) {
      swap(nums[i - 1], nums[i]);
      i -= 2;
    }
  }
}

int findFirstZero(const vector<int> &nums) {
  for (int i = 0; i < nums.size(); i++)
    if (nums[i] == 0)
      return i;
  return -1;
}

void optimized(vector<int> &nums) {
  int firstZero = findFirstZero(nums);
  if (firstZero == -1)
    return;
  for (int i = firstZero + 1; i < nums.size(); i++) {
    if (nums[i] != 0) {
      swap(nums[firstZero], nums[i]);
      firstZero++;
    }
  }
}

int main() {
  printTitle("Move Zeroes");
  vector<int> nums = {0, 1, 0, 3, 12};
  cout << "Solution: ";
  optimized(nums);
  printVector(nums);
  return 0;
}
