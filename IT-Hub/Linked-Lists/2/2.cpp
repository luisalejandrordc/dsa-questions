#include "../../../include/utils.h"
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

int main() {
  printTitle("Linked List Cycle");
  ListNode *head;
  cout << "Solution: " << hasCycle(head) << endl;
  return 0;
}
