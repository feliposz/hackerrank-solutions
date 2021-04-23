

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/



void traverse(struct node *n, int hd, int depth, int *result, int *result_depth) {
    if (n) {
        if (depth < result_depth[250+hd]) {
            result[250+hd] = n->data;
            result_depth[250+hd] = depth;
        }
        traverse(n->left, hd-1, depth+1, result, result_depth);
        traverse(n->right, hd+1, depth+1, result, result_depth);
    }
}

void topView( struct node *root) {
    int result[500], depth[500];
    memset(result, 0, sizeof(result));
    for (int i = 0; i < 500; i++) {
        depth[i] = 1000000;
    }
    traverse(root, 0, 0, result, depth);
    for (int i = 0; i < 500; i++) {
        if (result[i] > 0) {
            printf("%d ", result[i]);            
        }
    }
}

// 1 2 4 14 23 37 108 111 115 116 83 84 85 


