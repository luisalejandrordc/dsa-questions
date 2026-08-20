#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

int *findGreaterEqual(vector<int> &vec, int target) {
  // Binary Search
  int left = 0, right = vec.size();
  while (left < right) {
    int idx = left + (right - left) / 2;
    if (vec[idx] < target)
      left = idx + 1;
    else
      right = idx;
  }
  return left == vec.size() ? nullptr : &vec[left];
}

int *findGreaterEqual1(vector<int> &vec, int target) {
  for (int &x : vec)
    if (x >= target)
      return &x;
  return nullptr;
}

int lengthOfLIS(vector<int> &nums) {
  vector<int> tails;
  // tails[idx] = smallest tail of a strictly increasing
  // subsequence of length idx+1
  for (const int x : nums) {
    int *p = findGreaterEqual(tails, x);
    if (p == nullptr)
      tails.push_back(x);
    else
      *p = x; // replace the pointing value with x
  }
  // printVector(tails);
  return tails.size();
}

int main() {
  printTitle("Longest Increasing Subsequence");
  // vector<int> nums = {0, 1, 0, 3, 2, 3};
  vector<int> nums;
  for (int i = 0; i < 2500; i++)
    nums.push_back(i + 1);
  printVector(nums);
  int solution = timedCall(lengthOfLIS, nums);
  cout << "Solution: " << solution << endl;
  return 0;
}
