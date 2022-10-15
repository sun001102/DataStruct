struct ListNode* FindKthToTail(struct ListNode* pHead, int k) {
    // write code here
    struct ListNode* fast, * slow;
    slow = fast = pHead;
    while (k--)
    {
        if (fast == NULL)
            return NULL;
        fast = fast->next;
    }
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}