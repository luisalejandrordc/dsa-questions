#include "../../../include/utils.h"
#include <iostream>

using namespace std;

int climbStairs(int n) {
  if (n == 0)
    return 1;
  int num = 0;
  if (n >= 1)
    num += climbStairs(n - 1);
  if (n > 1)
    num += climbStairs(n - 2);
  return num;
}

int main() {
  printTitle("Climbing Stairs");
  for (int i = 1; i <= 10; i++) {
    cout << "For n = " << i << " -> " << climbStairs(i) << endl;
  }
  return 0;
}
