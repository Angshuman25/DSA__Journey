/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0 , head);
        ListNode* connection = &dummy;

        // 1.Move to the node right before the sublist starts
        for(int i = 1; i < left; i++) {
            connection = connection->next;
        }

        // The Sublist starts at connection->next (this will become the new tail)
        ListNode* tail = connection->next;

        // 2.Exact same logic of Leetcode 206(Reverse Linked List)
        ListNode* prev = NULL;
        ListNode* curr = tail;
        ListNode* next = NULL;

        for(int i = 0; i <= right - left; i++) {
           next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = next;
        }
        
        // 3.Reconnect the isolated sublist back to the main chain
        connection->next = prev; // Connect left outer side to the next sublist head
        tail->next = curr; // Connect the sublist tail to the right outer side

        return dummy.next;
    }
};