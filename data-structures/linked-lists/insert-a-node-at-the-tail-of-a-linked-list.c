

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {

    SinglyLinkedListNode* node = malloc(sizeof(SinglyLinkedListNode));
    node->data = data;
    node->next = NULL;

    if (head) {
        SinglyLinkedListNode *p = head;
        while (p->next) {
            p = p->next;    
        }        
        p->next = node;
    } else {
        head = node;
    }

    return head;
}


