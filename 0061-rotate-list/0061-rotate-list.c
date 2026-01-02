/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    struct ListNode* tail = head;
    int length = 1;
    
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }
    k = k % length;
    if (k == 0) return head;

    tail->next = head; 
    int stepsToNewTail = length - k;
    struct ListNode* newTail = tail;
    
    while (stepsToNewTail > 0) {
        newTail = newTail->next;
        stepsToNewTail--;
    }

    struct ListNode* newHead = newTail->next; 
    newTail->next = NULL; 

    return newHead;
}