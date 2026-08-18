#include "../../../include/utils.h"
#include <iostream>

using namespace std;

int climbStairs(int n) {
  if (n == 1 || n == 2)
    return n;
  int a = 1, b = 2;
  for (int i = 3; i <= n; i++) {
    int temp = b;
    b = a + b;
    a = temp;
  }
  return b;
}

int main() {
  printTitle("Climbing Stairs");
  for (int i = 1; i <= 10; i++)
    cout << "For n = " << i << " -> " << climbStairs(i) << endl;
  return 0;
}
