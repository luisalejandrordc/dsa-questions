#include "../../../include/utils.h"
#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

const unordered_set<string> OPERATORS = {"+", "-", "*", "/"};

int performOperation(string op, int num1, int num2) {
  if (op == "+")
    return num1 + num2;
  if (op == "-")
    return num1 - num2;
  if (op == "*")
    return num1 * num2;
  return num1 / num2;
}

// RPN -> Reverse Polish Notation
int evalRPN(vector<string> &tokens) {
  stack<int> nums;
  for (const string &s : tokens) {
    if (OPERATORS.count(s)) {
      int num2 = nums.top();
      nums.pop();
      int num1 = nums.top();
      nums.pop();
      nums.push(performOperation(s, num1, num2));
    } else
      nums.push(stoi(s));
  }
  return nums.top();
}

int main() {
  printTitle("Evaluate Reverse Polish Notation");
  // vector<string> tokens = {"3", "4", "+", "5", "*"};
  vector<string> tokens = {"-9", "2", "/"};
  cout << "Solution: " << evalRPN(tokens) << endl;
  return 0;
}
