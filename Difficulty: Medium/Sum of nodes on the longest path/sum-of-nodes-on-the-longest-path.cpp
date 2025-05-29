/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void solve(Node* root, int len, int sum, int &maxLen, int &maxSum) {
    if (!root) {
        if (len > maxLen) {
            maxLen = len;
            maxSum = sum;
        } else if (len == maxLen) {
            maxSum = max(maxSum, sum);
        }
        return;
    }

    sum += root->data;

    solve(root->left, len + 1, sum, maxLen, maxSum);
    solve(root->right, len + 1, sum, maxLen, maxSum);
}
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int maxLen = 0, maxSum = 0;
        solve(root, 0, 0, maxLen, maxSum);
        return maxSum; 
    }
};