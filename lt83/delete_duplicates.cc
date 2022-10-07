// lt83: Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val{0}, next{nullptr} {}
  ListNode(int x) : val{x}, next{nullptr} {}
  ListNode(int x, ListNode *next) : val{x}, next{next} {}
};

// Given a sorted list, deletes all duplicates in place.
ListNode *deleteDuplicates(ListNode *head) {
  ListNode *curr = head;
  // if there is at least two nodes
  while (curr && curr->next) {
    if (curr->next->val == curr->val)
      // curr->next is a duplicate, removes it
      // we don't need to move curr in this case since curr and curr->next->next
      // can also be duplicate and we want to compare
      curr->next = curr->next->next;
    else
      // move the curr to the next node
      curr = curr->next;
  }
  return head;
}
