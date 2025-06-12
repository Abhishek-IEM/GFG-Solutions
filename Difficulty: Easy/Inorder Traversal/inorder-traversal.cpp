/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void helper(Node* root, vector<int>& ans)
    {
        if(root == NULL) return;
        helper(root->left, ans);
        ans.push_back(root->data);
        helper(root->right, ans);
    }
    vector<int> inOrder(Node* root) {
        // Your code here
         vector <int> ans;
        helper(root, ans);
        return ans;
    }
};