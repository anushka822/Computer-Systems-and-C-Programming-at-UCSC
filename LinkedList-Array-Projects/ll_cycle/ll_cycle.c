#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
// Start with two-pointers at the head of the list. One will be called fast_ptr, and the other will be called slow_ptr.

    node* slow_ptr = head;
    node* fast_ptr = head;

    // Traverse the linked list
    

    // Advance fast_ptr by two nodes. If not possible cos of  null pointer, we found end list, 
    // and therefore the list is acyclic.

    while (fast_ptr != NULL && fast_ptr->next != NULL) {

        // Move the fast pointer by two steps
        fast_ptr = fast_ptr->next->next;
        
        // Advance slow_ptr by one node. (A null pointer check is unnecessary. Why?)
        slow_ptr = slow_ptr->next;

         //If the fast_ptr and slow_ptr ever point to the same node, the list is cyclic.
        if (slow_ptr == fast_ptr) {
            return 1; 
        }
    }

    // If we reach here, there is no cycle in the linked list
    return 0;
}
