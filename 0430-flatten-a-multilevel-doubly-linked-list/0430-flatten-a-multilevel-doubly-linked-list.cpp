/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        // Base Case
        if(head == NULL) {
            return head;
        }
        Node* curr = head;
        while(curr != NULL) {
            if(curr->child != NULL) {   // Child Exists
                // Flatten the Child Nodes
                Node* next = curr->next;
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = NULL;  

                // Find the tail of the new linked list
                while(curr->next != NULL) {
                    curr = curr->next;
                }

                // Attach tail with next node
                if(next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;   // Resuming Traversal
        }
        return head;
    }
};