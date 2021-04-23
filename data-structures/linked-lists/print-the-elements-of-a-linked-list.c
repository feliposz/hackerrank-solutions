

// Complete the printLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void printLinkedList(SinglyLinkedListNode* head) {
    for (SinglyLinkedListNode *p = head; p; p = p->next) {
        printf("%d\n", p->data);
    }
}


