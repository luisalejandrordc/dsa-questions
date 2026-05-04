#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, char> openToClose = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
unordered_map<char, char> closeToOpen = {{')', '('}, {']', '['}, {'}', '{'}};

bool validParentheses(string s) {
  // Last open bracket, must be the first to be closed (LIFO)
  stack<char> history;
  for (char c : s) {
    if (openToClose.count(c))
      history.push(c);
    else {
      if (history.empty())
        return false;
      if (history.top() == closeToOpen[c])
        history.pop();
      else
        return false;
    }
  }
  return history.empty() ? true : false;
}

int main() {
  cout << "It's Showtime Folks!" << endl;
  cout << "Result: " << validParentheses("()") << endl;
  cout << "Result: " << validParentheses("()[]{}") << endl;
  cout << "Result: " << validParentheses("()[") << endl;
  cout << "Result: " << validParentheses("()]") << endl;
  cout << "Result: " << validParentheses("[(])") << endl;
  return 0;
}
