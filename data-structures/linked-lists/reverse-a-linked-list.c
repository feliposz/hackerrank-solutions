

// Complete the reverse function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* revHelper(SinglyLinkedListNode* curr, SinglyLinkedListNode *prev) {
    SinglyLinkedListNode *next = curr->next;
    curr->next = prev;
    if (next == NULL) {
        return curr;
    } else {
        return revHelper(next, curr);
    }
}

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    if (head) {
        head = revHelper(head, NULL);
    }
    return head;
}


