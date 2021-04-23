

// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode **visited = malloc(1000 * sizeof(SinglyLinkedListNode *));
    int size = 0;
    
    for (SinglyLinkedListNode *p = head; p; p = p->next) {
        for (int i = 0; i < size; i++) {
            if (p == visited[i]) {
                return true;
            }
        }
        visited[size++] = p;
    }
    
    return false;

}


