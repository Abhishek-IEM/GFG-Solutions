//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector<int> diagonal(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector<int> diagonalNode = diagonal(root);
        for(int i = 0;i<diagonalNode.size();i++)
        cout<<diagonalNode[i]<<" ";
        cout<<endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


void find(Node* root, int pos, int &l)
{
    if(!root) return;
    l = max(pos, l);
    find(root->left, pos+1, l);
    find(root->right, pos+1, l);
}

void findDig(Node* root, int pos, vector<vector<int>> &ans)
{
    if(!root) return;
    ans[pos].push_back(root->data);
    findDig(root->left, pos+1, ans);
    findDig(root->right, pos, ans);
}

vector<int> diagonal(Node *root)
{
   // your code here
   int l = 0;
   find(root, 0, l);
   vector<vector<int>> ans(l+1);
   
   findDig(root, 0, ans);
   
   vector<int> temp;
   
   for(int i=0;i<ans.size();i++)
   for(int j=0;j<ans[i].size();j++)
   temp.push_back(ans[i][j]);
   
   return temp;
}