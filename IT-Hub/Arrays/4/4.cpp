#include "../../../include/utils.h"
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void brute_force(vector<int> &nums, int k) {
  if (k > nums.size())
    k = k % nums.size();
  for (int i = 0; i < k; i++)
    for (int j = nums.size() - 1; j > 0; j--)
      swap(nums[j - 1], nums[j]);
}

void test(vector<int> &nums, int k) {
  int len = nums.size();
  if (len == 0)
    return;
  k %= len;
  int a = 0, b = k;
  while (a != b && b != k - 1) {
    swap(nums[a], nums[b]);
    if (k <= len / 2)
      a = a == k - 1 ? 0 : a + 1;
    else
      a = min(k - 1, a + 1);
    b = b == len - 1 ? 0 : b + 1;
  }
}

void extra(vector<int> &nums, int k) {
  int len = nums.size();
  if (len == 0)
    return;
  k %= len;
  vector<int> temp(len);
  for (int i = len - k, j = 0; i < len; i++, j++)
    temp[j] = nums[i];
  for (int i = 0, j = k; j < len; i++, j++)
    temp[j] = nums[i];
  nums = temp;
}

void optimized(vector<int> &nums, int k) {
  int len = nums.size();
  if (len == 0)
    return;
  k %= len;
  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k, nums.end());
}

int main() {
  printTitle("Rotate Array");
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  cout << "Solution: ";
  optimized(nums, 4);
  printVector(nums);
  return 0;
}
