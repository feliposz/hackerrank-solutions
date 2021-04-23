

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) {
      if (root) {
          if (root->data == v1 || root->data == v2) {
              return root;
          } else {
              Node *left = lca(root->left, v1, v2);
              Node *right = lca(root->right, v1, v2);
              if (left && right) {
                  return root;
              } else if (left) {
                  return left;
              } else {
                  return right;
              }
          }
      }
      return NULL;
    }


