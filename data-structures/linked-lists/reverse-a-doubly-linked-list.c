

// Complete the reverse function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    DoublyLinkedListNode *last = NULL;
    for (DoublyLinkedListNode *p = head; p; p = p->prev) {
        DoublyLinkedListNode *tmp = p->prev;
        p->prev = p->next;
        p->next = tmp;
        last = p;
    }
    return last;
}


