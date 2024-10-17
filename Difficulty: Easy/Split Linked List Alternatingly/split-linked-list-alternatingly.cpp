//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        vector<Node*> ans;
        if(head == NULL || head->next == NULL) return ans;
        Node* temp = head;
        Node* n1 = head;
        Node *t1 = n1;
        Node* n2 = head->next;
        Node* t2 = n2;
        while (t2 != NULL && t2->next != NULL) {
            t1->next = t2->next;
            t1 = t1->next;
            t2->next = t2->next->next;
            t2 = t2->next;
        }
        t1->next = NULL;
    
        if (t2 != NULL) {
            t2->next = NULL;
        }
    
        ans.push_back(n1);
        ans.push_back(n2);
        return ans;
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends