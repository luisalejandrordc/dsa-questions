#include "../../../include/utils.h"
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
  stack<int> input, output;

public:
  void move() {
    if (output.empty())
      while (!input.empty()) {
        output.push(input.top());
        input.pop();
      }
  }
  void push(int x) { input.push(x); }
  int pop() {
    move();
    int num = output.top();
    output.pop();
    return num;
  }
  int peek() {
    move();
    return output.top();
  }
  bool empty() { return input.empty() && output.empty(); }
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
    vector<int> nums;
    temp = input;
    while (!temp.empty()) {
      nums.push_back(temp.top());
      temp.pop();
    }
    for (int x : nums) {
      if (started)
        cout << ", ";
      cout << x;
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
