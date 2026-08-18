#include "../../../include/utils.h"
#include <iostream>

using namespace std;

int climbStairs(int n) {
  if (n == 0) // Top reached
    return 1;
  if (n < 0) // Top exceeded
    return 0;
  return climbStairs(n - 1) + climbStairs(n - 2);
}

int main() {
  printTitle("Climbing Stairs");
  for (int i = 1; i <= 10; i++)
    cout << "For n = " << i << " -> " << climbStairs(i) << endl;
  return 0;
}
