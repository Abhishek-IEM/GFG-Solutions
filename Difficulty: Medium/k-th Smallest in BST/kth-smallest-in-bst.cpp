/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int count = 0;
    int result = -1;
    
    void inOrder(Node* root, int k) {
        if (root == NULL) return;
        
        inOrder(root->left, k);
        
        count++;
        if (count == k) {
            result = root->data;
            return;
        }
        
        inOrder(root->right, k);
    }
    
    int kthSmallest(Node *root, int k) {
        count = 0;
        result = -1;
        inOrder(root, k);
        return result;
    }
};
