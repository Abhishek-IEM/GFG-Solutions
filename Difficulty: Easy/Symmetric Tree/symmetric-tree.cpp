/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool solve(Node *left, Node *right)
    {
        if(!left || !right) return left == right;
        if(left->data != right->data) return false;
        return solve(left->left, right->right) && solve(left->right, right->left);
    }
    
    bool isSymmetric(Node* root) {
        // Code here
        Node *left = root->left;
        Node *right = root->right;
        return solve(left, right);
    }
};