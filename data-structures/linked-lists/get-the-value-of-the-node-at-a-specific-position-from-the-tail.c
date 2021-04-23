

// Complete the getNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
 
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    int size = 0;
    for (SinglyLinkedListNode *p = head; p; p = p->next) {
        size++;
    }
    int position = size - positionFromTail;
    for (SinglyLinkedListNode *p = head; p; p = p->next) {
        position--;
        if (position == 0)
        {
            return p->data;
        }        
    }
    return -1;
}


