#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &nums) {
  int len = nums.size();
  cout << "[";
  for (int i = 0; i < len; i++) {
    cout << nums[i];
    if (i != len - 1)
      cout << "\t";
  }
  cout << "]" << endl;
}

void backtrack(vector<int> &nums, int a, vector<vector<int>> &result) {
  if (a == nums.size() - 1) {
    result.push_back(nums);
    return;
  }
  for (int b = a; b < nums.size(); b++) {
    swap(nums[a], nums[b]);
    backtrack(nums, a + 1, result);
    swap(nums[a], nums[b]);
  }
}

vector<vector<int>> permute(vector<int> &nums) {
  vector<vector<int>> result;
  backtrack(nums, 0, result);
  return result;
}

int main() {
  cout << "It's Showtime Folks!" << endl;
  cout << "Permutations:" << endl;
  vector<int> nums = {1, 2, 3};
  for (vector<int> v : permute(nums))
    printVector(v);
  return 0;
}
