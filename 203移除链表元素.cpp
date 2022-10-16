struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head, * prev = NULL;
    while (cur)
    {
        if (cur->val == val)
        {
            if (cur == head)
            {
                head = head->next;
                free(cur);
                cur = head;
            }
            else {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}