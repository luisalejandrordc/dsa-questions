#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

int computeWater(vector<int> &height, int l, int r) {
  if (r - l <= 1)
    return 0;
  int h = min(height[l], height[r]);
  int water = 0;
  for (int i = l + 1; i < r; i++)
    water += h - height[i];
  return water;
}

int trap(vector<int> &height) {
  if (height.size() <= 2)
    return 0;
  int water = 0;
  // Left-to-right direction
  int l = 0;
  for (int r = l + 1; r < height.size(); r++)
    if (height[r] >= height[l]) {
      water += computeWater(height, l, r);
      l = r;
    }
  // Right-to-left direction
  int r = height.size() - 1;
  for (int l = r - 1; l >= 0; l--)
    if (height[l] > height[r]) {
      water += computeWater(height, l, r);
      r = l;
    }
  return water;
}

int main() {
  printTitle("Trapping Rain Water");
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << "Solution: " << trap(height) << endl;
  return 0;
}
