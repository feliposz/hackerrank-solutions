

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        Node *n =  new Node(data);
        if (!root) {
            root = n;
        } else if (data < root->data) {
            if (root->left) {
                insert(root->left, data);
            } else {
                root->left = n;
            }
        } else if (data >= root->data) {
            if (root->right) {
                insert(root->right, data);
            } else {
                root->right = n;
            }
        }
        return root;
    }


