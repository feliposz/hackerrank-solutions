

// Complete the removeDuplicates function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    if (head && head->next) {
        if (head->data == head->next->data) {
            head = removeDuplicates(head->next);
        } else {
            head->next = removeDuplicates(head->next);
        }
    }
    return head;
}


