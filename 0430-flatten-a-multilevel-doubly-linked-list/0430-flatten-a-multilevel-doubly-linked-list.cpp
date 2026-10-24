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
            if(curr->child != NULL) {   // If Child Exists for currnt node , then we are going to execute this if statement otherwise we will update the curr for the next node 

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
            curr = curr->next;   // Resuming Traversal , If Child dont exist for previous node then we are going in next node by updating curr 
        }
        return head;
    }
};