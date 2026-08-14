#include "../../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

ListNode *arrayToLinkedList(const vector<int> &nums) {
  ListNode *head = new ListNode();
  ListNode *curr = head;
  for (const int &x : nums) {
    curr->next = new ListNode(x);
    curr = curr->next;
  }
  return head->next;
}

void printLinkedList(ListNode *head) {
  ListNode *curr = head;
  cout << "{";
  while (curr != nullptr) {
    if (curr != head)
      cout << ", ";
    cout << curr->val;
    curr = curr->next;
  }
  cout << "}" << endl;
}

ListNode *reverseLinkedList(ListNode *head) {
  ListNode *curr = head;
  ListNode *reve = nullptr;
  while (curr != nullptr) {
    reve = new ListNode(curr->val, reve);
    curr = curr->next;
  }
  return reve;
}

int main() {
  printTitle("Reverse a Linked List");
  vector<int> nums = {1, 2, 3, 4, 5};
  ListNode *head = arrayToLinkedList(nums);
  ListNode *reve = reverseLinkedList(head);
  cout << "Solution: ";
  printLinkedList(reve);
  return 0;
}
