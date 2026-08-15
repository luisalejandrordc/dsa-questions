#include "../../../include/utils.h"
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

const unordered_map<char, char> BRACKETS = {
    {'(', ')'},
    {'{', '}'},
    {'[', ']'},
};

bool isValid(string s) {
  // Last open bracked must be the first to be closed (LIFO)
  stack<char> open;
  for (const char &c : s)
    if (BRACKETS.count(c))
      open.push(c);
    else {
      if (open.empty() || c != BRACKETS.at(open.top()))
        return false;
      open.pop();
    }
  return open.empty() ? true : false;
}

int main() {
  printTitle("Valid Parentheses");
  // string s = "[{()}]";
  string s = "[(])";
  string solution = isValid(s) ? "True" : "False";
  cout << "Solution: " << solution << endl;
  return 0;
}
