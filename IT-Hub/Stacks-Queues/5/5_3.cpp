#include "../../../include/utils.h"
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
  vector<int> maxWindow;
  deque<int> maxs;
  for (int i = 0; i < nums.size(); i++) {
    // 1. Remove index that is outside the window
    if (!maxs.empty() && maxs.front() == i - k)
      maxs.pop_front();
    // 2. Remove elements that are lower than the new element
    while (!maxs.empty() && nums[maxs.back()] <= nums[i])
      maxs.pop_back();
    // 3. Push back new element to deque
    maxs.push_back(i);
    // 4. Push back max element to maxWindow
    if (i >= k - 1)
      maxWindow.push_back(nums[maxs.front()]);
  }
  return maxWindow;
}

int main() {
  printTitle("Sliding Window Maximum");
  // vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  vector<int> nums;
  nums.reserve(100000);
  for (int i = 10000; i >= 0; i--)
    for (int j = 1; j <= 10; j++)
      nums.push_back(i);
  cout << "Solution: ";
  printVector(maxSlidingWindow(nums, 50000));
  return 0;
}
