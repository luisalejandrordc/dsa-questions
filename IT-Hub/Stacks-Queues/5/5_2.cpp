#include "../../../include/utils.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int findMaximum(queue<int> window) {
  int maximum = window.front();
  while (!window.empty()) {
    maximum = max(maximum, window.front());
    window.pop();
  }
  return maximum;
}

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
  queue<int> window;
  vector<int> max_window;
  int lastMax, removed;
  for (int i = 0; i < k && i < nums.size(); i++)
    window.push(nums[i]);
  lastMax = findMaximum(window);
  max_window.push_back(lastMax);
  for (int i = k; i < nums.size(); i++) {
    removed = window.front();
    window.push(nums[i]);
    window.pop();
    if (nums[i] >= lastMax)
      lastMax = nums[i];
    else if (removed == lastMax)
      lastMax = findMaximum(window);
    max_window.push_back(lastMax);
  }
  return max_window;
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
