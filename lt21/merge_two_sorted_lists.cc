// lt21: Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val{0}, next{nullptr} {}
  ListNode(int x) : val{x}, next{nullptr} {}
  ListNode(int x, ListNode *next) : val{x}, next{next} {}
};

// Merges two sorted lists into a single sorted list.
// The nodes in the new lists are from list1 and list2 (nodes are moved instead
// of copied).
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  // if one of the list is empty, return the non-empty one
  // if both are empty, return nullptr
  if (!list1) return list2;
  if (!list2) return list1;
  // both are non-empty, list1 and list2 points to nodes
  // reduce the problem by one node
  ListNode *head = list1->val < list2->val ? list1 : list2;
  ListNode *next = list1->val < list2->val ? mergeTwoLists(list1->next, list2)
                                           : mergeTwoLists(list1, list2->next);
  head->next = next;
  return head;
}
