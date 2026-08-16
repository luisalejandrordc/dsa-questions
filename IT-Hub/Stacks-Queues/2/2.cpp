#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

class MinStack {
  vector<int> elements;
  vector<int> minValue;

public:
  MinStack() {
    elements = {};
    minValue = {};
  };

  void push(int value) {
    elements.push_back(value);
    if (minValue.empty())
      minValue.push_back(value);
    else
      minValue.push_back(min(minValue.back(), value));
  }
  void pop() {
    if (!elements.empty()) {
      elements.pop_back();
      minValue.pop_back();
    }
  }
  int top() { return elements.back(); }
  int getMin() { return minValue.back(); }
  void print() { printVector(elements); }
};

int main() {
  printTitle("Min Stack");
  MinStack my_stack = MinStack();
  my_stack.push(5);
  my_stack.push(4);
  my_stack.push(3);
  my_stack.push(2);
  my_stack.push(1);
  my_stack.print();
  cout << "Top value: " << my_stack.top() << endl;
  cout << "Min value: " << my_stack.getMin() << endl;
  my_stack.pop();
  my_stack.pop();
  my_stack.print();
  cout << "Top value: " << my_stack.top() << endl;
  cout << "Min value: " << my_stack.getMin() << endl;
  return 0;
}
