//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution{
  public:
    /*You are required to complete this method */
    int getHeight(Node* root)
    {
        if(!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right)); 
    }
    
    int balanced(Node* root)
    {
        return getHeight(root->left) - getHeight(root->right);
    }
    
    Node *rightRotation(Node* root)
    {
        Node* child = root->left;
        Node* childRight = child->right;
        child->right = root;
        root->left = childRight;
        
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        child->height = 1 + max(getHeight(child->left), getHeight(child->right)); 
    
        return child;
    }
    
    Node *leftRotation(Node* root)
    {
        Node* child = root->right;
        Node* childLeft = child->left;
        child->left = root;
        root->right = childLeft;
        
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        child->height = 1 + max(getHeight(child->left), getHeight(child->right)); 
    
        return child;
    }
    
    Node* insertToAVL(Node* root, int key)
    {
        //Your code here
        if(!root) return new Node(key);
        
        if(root->data > key) //left side
        root->left = insertToAVL(root->left, key);
        
        else  if(root->data < key) //right side
        root->right = insertToAVL(root->right, key);
        
        else return root;
        
        root->height = 1 + max(getHeight(root->left), getHeight(root->right)); 
        
        int balance = balanced(root);
        
        //left left case
        if(balance > 1 && key < root->left->data)
        {
            return rightRotation(root);
        }
        else if(balance < -1 && key > root->right->data) //right right
        {
            return leftRotation(root);
        }
        else if(balance > 1 && key > root->left->data) //left right
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
        else if(balance < -1 && key < root->right->data) // right left
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
        else return root;
    }
};

//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends