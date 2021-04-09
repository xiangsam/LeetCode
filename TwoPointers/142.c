#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head, *slow = head;
	do{
		if(fast == NULL || fast->next == NULL)
			return NULL;
	    fast = fast->next->next;
		slow = slow->next;
	}while(fast != slow);
	fast = head;
	while(fast != slow){
		slow = slow->next;
		fast = fast->next;
	}return fast;
}
