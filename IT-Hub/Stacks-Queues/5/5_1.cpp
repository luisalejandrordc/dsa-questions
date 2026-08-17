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
  vector<int> max_win;
  for (int i = 0; i < k && i < nums.size(); i++)
    window.push(nums[i]);
  max_win.push_back(findMaximum(window));
  for (int i = k; i < nums.size(); i++) {
    window.pop();
    window.push(nums[i]);
    max_win.push_back(findMaximum(window));
  }
  return max_win;
}

int main() {
  printTitle("Sliding Window Maximum");
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  cout << "Solution: ";
  printVector(maxSlidingWindow(nums, 3));
  return 0;
}
