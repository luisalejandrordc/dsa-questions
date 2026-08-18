#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

int recs(vector<int> &nums, int start) {
  if (start > nums.size())
    return 0;
  int maxMoney = 0;
  for (int i = start; i < nums.size() && i < start + 2; i++)
    maxMoney = max(maxMoney, nums[i] + recs(nums, i + 2));
  return maxMoney;
}

int rob(vector<int> &nums) { return recs(nums, 0); }

int main() {
  printTitle("House Robber");
  // vector<int> nums = {2, 7, 9, 3, 1};
  vector<int> nums = {
      226, 174, 214, 16,  218, 48,  153, 131, 128, 17,  157, 142, 88,  43,
      37,  157, 43,  221, 191, 68,  206, 23,  225, 82,  54,  118, 111, 46,
      80,  49,  245, 63,  25,  194, 72,  80,  143, 55,  209, 18,  55,  122,
      65,  66,  177, 101, 63,  201, 172, 130, 103, 225, 142, 46,  86,  185,
      62,  138, 212, 192, 125, 77,  223, 188, 99,  228, 90,  25,  193, 211,
      84,  239, 119, 234, 85,  83,  123, 120, 131, 203, 219, 10,  82,  35,
      120, 180, 249, 106, 37,  169, 225, 54,  103, 55,  166, 124};
  // vector<int> nums = {5, 1, 1, 20};
  cout << "Solution: " << rob(nums) << endl;
  return 0;
}
