/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    bool check(Node *n, int min, int max)
    {
        if (n) {
            if (n->data < min || n->data > max) {
                return false;
            } else {
                return check(n->left, min, n->data - 1) && check(n->right, n->data + 1, max);
            }
        }
        return true;
    }

	bool checkBST(Node* root) {
		return check(root, 0, 10000);
	}
