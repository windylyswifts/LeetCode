struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    if (count == n) {
        return head->next;
    }
    temp = head;
    for (int i = 0; i < count - n - 1; i++) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}