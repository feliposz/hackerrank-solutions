

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    for (SinglyLinkedListNode *a = head1; a; a = a->next) {
        for (SinglyLinkedListNode *b = head2; b; b = b->next) {
            if (a == b) {
                return a->data;
            }   
        }
    }
    return -1;
}


