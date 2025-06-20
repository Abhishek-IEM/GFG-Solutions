/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    void preorder(Node *root, vector<int> &ans)
   {
       if(!root){
           ans.push_back(-1);
           return;
       }
       ans.push_back(root->data);
       preorder(root->left, ans);
       preorder(root->right, ans);
   }
   
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int> ans;
        preorder(root, ans);
        return ans;
        
    }
    
     int i = 0;
    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        
        // Your code here
        int val = arr[i];
        i++;
        if(val == -1) return NULL;
        Node *nn = new Node(val);
        nn->left = deSerialize(arr);
        nn->right = deSerialize(arr);
        return nn;
    }
};