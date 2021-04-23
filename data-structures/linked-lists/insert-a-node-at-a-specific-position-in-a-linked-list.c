

// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode *node = malloc(sizeof(SinglyLinkedListNode));
    node->data = data;
    node->next = NULL;
    
    if (position == 0) {
        node->next = head;
        head = node;
    } else {
        SinglyLinkedListNode *prev = NULL; 
        SinglyLinkedListNode *curr = head; 
        for (int i = 0; (i < position) && curr; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = node;
        node->next = curr;
    }
    
    return head;

}


