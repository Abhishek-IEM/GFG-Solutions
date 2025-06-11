// Class that contains the logic to build the binary tree
/*
Definition of the Node class
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
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    int find(vector<int> &in, int target, int start, int end)
    {
        for(int i=start;i<=end;i++)
        {
            if(in[i] == target) return i;
        }
        return -1;
    }
    
    Node* Tree(vector<int> &in,vector<int> &pre, int inStart, int inEnd, int index)
    {
        if(inStart > inEnd) return NULL;
        
        Node* root = new Node(pre[index]);
        
        int pos = find(in, pre[index], inStart, inEnd);
        
        root->left = Tree(in, pre, inStart, pos-1, index+1);
        root->right = Tree(in, pre, pos+1, inEnd, index+(pos-inStart)+1);
        
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n = inorder.size();
        return Tree(inorder,preorder,0,n-1,0);
    }
};


