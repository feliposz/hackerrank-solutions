

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* head = head1;
    
    if (head1 == NULL) {
        head = head2;
    } else if (head2 == NULL) {
        head = head1;
    } else if (head1->data < head2->data) {
        head = head1;
        head->next = mergeLists(head1->next, head2);
    } else {
        head = head2;
        head->next = mergeLists(head1, head2->next);
    }
    return head;
}


