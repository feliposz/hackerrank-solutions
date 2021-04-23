

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
int treeHeight(struct node *root) {
    if (root) {
        int left = treeHeight(root->left);
        int right = treeHeight(root->right);
        return 1 + ((left > right) ? left : right);
    }
    return 0;
}

void printLevel(struct node *root, int depth) {
    if (root) {
        if (depth == 0) {
            printf("%d ", root->data);
        } else if (depth > 0) {
            printLevel(root->left, depth - 1);
            printLevel(root->right, depth - 1);
        }
    }
}

void levelOrder(struct node *root) {
    int height = treeHeight(root);
    //printf("h=%d\n", height);
    for (int i = 0; i < height; i++) {
        printLevel(root, i);
    }
}


