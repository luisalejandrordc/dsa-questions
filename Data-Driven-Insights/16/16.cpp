#include <array>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *arrayToLinkedList(vector<int> &nums) {
  ListNode *dummy = new ListNode();
  ListNode *curr = dummy;
  for (int &n : nums) {
    curr->next = new ListNode(n);
    curr = curr->next;
  }
  curr->next = dummy->next; // Create a cycle
  return dummy->next;
}

void printLinkedList(ListNode *head) {
  cout << "[";
  ListNode *curr = head;
  while (curr != nullptr) {
    cout << curr->val;
    curr = curr->next;
    if (curr != nullptr)
      cout << "\t";
  }
  cout << "]" << endl;
}

void printAddresses(unordered_set<ListNode *> nodes) {
  cout << "[\t";
  for (ListNode *node : nodes) {
    cout << node << "\t";
  }
  cout << "]" << endl;
}

bool hasCycle(ListNode *head) {
  unordered_set<ListNode *> nodes;
  ListNode *curr = head;
  while (curr != nullptr) {
    if (nodes.count(curr))
      return true;
    nodes.insert(curr);
    printAddresses(nodes);
    curr = curr->next;
  }
  return false;
}

int main() {
  cout << "It's Showtime Folks!" << endl;
  vector<int> nums = {1, 2, 3, 4, 5};
  ListNode *head = arrayToLinkedList(nums);
  // printLinkedList(head);
  if (hasCycle(head))
    cout << "The Linked List has a Cycle" << endl;
  else
    cout << "The Linked List does not have any Cycle" << endl;
  return 0;
}
