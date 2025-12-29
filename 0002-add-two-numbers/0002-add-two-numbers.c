/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* temp;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    int leftovers = 0;

    while(l1 != NULL || l2 != NULL || leftovers != 0){
        int v1 = (l1 != NULL) ? l1->val : 0;
        int v2 = (l2 != NULL) ? l2->val : 0;

        int sum = v1 + v2 + leftovers;

        if(sum > 9){
            leftovers = 1;
            sum = sum % 10;
        } else {
            leftovers = 0;
        }
        temp = malloc(sizeof(struct ListNode));
        temp->val = sum;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        if(l1 != NULL) l1 = l1->next;
        if(l2 != NULL) l2 = l2->next;
    }
    return head;
}