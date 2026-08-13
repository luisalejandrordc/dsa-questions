#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

pair<int, int> brute_force(vector<int> &nums, int target) {
  int len = nums.size();
  for (int i = 0; i < len; i++)
    for (int j = i + 1; j < len; j++)
      if (nums[i] + nums[j] == target)
        return {i, j};
  return {-1, -1};
}

pair<int, int> optimized(vector<int> &nums, int target) {
  unordered_map<int, int> map;
  int len = nums.size();
  for (int i = 0; i < len; i++) {
    int x = target - nums[i];
    if (map.count(x))
      return {map[x], i};
    map[nums[i]] = i;
  }
  return {-1, -1};
}

void print_title(string title) {
  int spaces = 10;
  int dashes = spaces * 2 + title.length();
  for (int i = 0; i < dashes; i++)
    cout << "-";
  cout << endl;
  for (int i = 0; i < spaces; i++)
    cout << " ";
  cout << title << endl;
  for (int i = 0; i < dashes; i++)
    cout << "-";
  cout << endl;
}

int main() {
  print_title("Two Sum");
  vector<int> nums = {1, 2, 3, 4, 5};
  int target = 9;
  pair<int, int> solution = optimized(nums, target);
  cout << "Solution: (" << solution.first << ", " << solution.second << ")"
       << endl;
  return 0;
}
