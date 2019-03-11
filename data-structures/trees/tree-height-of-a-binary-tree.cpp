
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.
        int heightLeft = 0, heightRight = 0;
        if (root->left) {
          heightLeft = 1 + height(root->left);
        }
        if (root->right) {
          heightRight = 1 + height(root->right);
        }
        return heightLeft > heightRight ? heightLeft : heightRight;
    }


