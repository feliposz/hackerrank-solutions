

// Complete the sortedInsert function below.

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
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode *node = malloc(sizeof(DoublyLinkedListNode));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    
    if (head) {
        if (data < head->data) {
            node->next = head;
            head->prev = node;
            head = node;
        } else {
            DoublyLinkedListNode *prev = head;
            DoublyLinkedListNode *next = head->next;
            while (next && data > next->data) {
                prev = prev->next;
                next = next->next;
            }
            prev->next = node;
            node->prev = prev;
            node->next = next;
            if (next) {
                next->prev = node;                
            }
        }        
    } else {
        head = node;
    }

    return head;
}


