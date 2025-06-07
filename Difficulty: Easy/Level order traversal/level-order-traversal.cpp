/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> v;
            for (int i = 0; i < levelSize; i++) {
                Node* temp = q.front();
                q.pop();
                v.push_back(temp->data);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};