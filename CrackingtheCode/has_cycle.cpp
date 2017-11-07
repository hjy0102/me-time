/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node* hare;
    Node* tortoise; 
    
    hare = head;
    tortoise = head;
    
    while (tortoise && hare && hare->next){
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare){
            return true;
        }
    }
    return false;
  }
