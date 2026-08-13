#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

vector<int> brute_force(vector<int> &nums) { return nums; }

int main() {
  printTitle("Maximum Subarray");
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << "Solution: ";
  printVector(nums);
  return 0;
}
