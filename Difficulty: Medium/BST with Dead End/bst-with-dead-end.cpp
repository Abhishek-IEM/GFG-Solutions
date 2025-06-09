/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool isDeadEndUtil(Node* root, int minVal, int maxVal) {
        if (!root) return false;
    
        if (minVal == maxVal)
            return true;
    
        return isDeadEndUtil(root->left, minVal, root->data - 1) ||
               isDeadEndUtil(root->right, root->data + 1, maxVal);
    }
    
    bool isDeadEnd(Node *root) {
        return isDeadEndUtil(root, 1, INT_MAX);
    }

};