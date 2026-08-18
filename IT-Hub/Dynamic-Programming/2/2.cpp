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
  vector<int> nums = {114, 117, 207, 117, 235, 82,  90,  67,  143, 146,
                      53,  108, 200, 91,  80,  223, 58,  170, 110, 236,
                      81,  90,  222, 160, 165, 195, 187, 199, 114, 235,
                      197, 187, 69,  129, 64,  214, 228, 78,  188, 67,
                      205, 94,  205, 169, 241, 202, 144, 240};
  // vector<int> nums = {5, 1, 1, 20};
  cout << "Solution: " << rob(nums) << endl;
  return 0;
}
