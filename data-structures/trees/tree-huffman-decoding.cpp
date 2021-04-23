

/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;

*/


void decode_huff(node * root, string s) {
    node *n = root;
    for (auto c : s) {
        if (c == '0') {
            n = n->left;
        } else {
            n = n->right;
        }
        if (!n->left && !n->right) {
            putchar(n->data);
            n = root;
        }
    }
}


