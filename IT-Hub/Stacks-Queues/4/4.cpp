#include "../../../include/utils.h"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MyQueue {
  stack<int> input, output;

public:
  stack<int> reverseStack(stack<int> my_stack) {
    stack<int> reversed;
    while (!my_stack.empty()) {
      reversed.push(my_stack.top());
      my_stack.pop();
    }
    return reversed;
  }
  void push(int x) {
    input.push(x);
    output = reverseStack(input);
  }
  int pop() {
    int num = output.top();
    output.pop();
    input = reverseStack(output);
    return num;
  }
  int peek() { return output.top(); }
  bool empty() { return output.empty() ? true : false; }
  void print() {
    stack<int> temp = output;
    bool started = false;
    cout << "{";
    while (!temp.empty()) {
      if (started)
        cout << ", ";
      cout << temp.top();
      temp.pop();
      started = true;
    }
    cout << "}" << endl;
  }
};

int main() {
  printTitle("Implement Queue using Stacks");
  MyQueue my_queue;
  my_queue.push(1);
  my_queue.push(2);
  my_queue.push(3);
  my_queue.print();
  my_queue.pop();
  my_queue.print();
  cout << "Front: " << my_queue.peek() << endl;
  cout << "Empty: " << my_queue.empty() << endl;
  my_queue.pop();
  my_queue.pop();
  my_queue.print();
  return 0;
}
