

// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {

    if (position == 0) {
        return head->next;
    } else {
        SinglyLinkedListNode *p = head;
        for (int i = 0; i < position - 1; i++) {
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
}


