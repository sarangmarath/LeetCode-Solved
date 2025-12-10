/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int store1[1000], store2[1000];  
    int i = 0, j = 0;

    struct ListNode* current1 = l1;
    while (current1 != NULL) {
        store1[i++] = current1->val;
        current1 = current1->next;
    }

    struct ListNode* current2 = l2;
    while (current2 != NULL) {
        store2[j++] = current2->val;
        current2 = current2->next;
    }

    int carry = 0;
    int maxLen = i > j ? i : j;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* tail = dummy;

    for (int k = 0; k < maxLen; k++) {
        int x = k < i ? store1[k] : 0;
        int y = k < j ? store2[k] : 0;
        int sum = x + y + carry;
        carry = sum / 10;

        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;
        tail->next = node;
        tail = tail->next;
    }

    if (carry > 0) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = carry;
        node->next = NULL;
        tail->next = node;
    }

    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}
