//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}


// } Driver Code Ends


/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Function to merge two sorted linked list.
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *c = new Node(10);
    Node* tempC = c;
    while(temp1 && temp2)
    {
        if(temp1->data < temp2->data)
        {
            tempC->next = temp1;
            temp1 = temp1->next;
            tempC = tempC->next;
        }
        else
        {
            tempC->next = temp2;
            temp2 = temp2->next;
            tempC = tempC->next;
        }
    }
    if(temp1 == NULL)
    {
        if(temp2 != NULL)
        {
            tempC->next = temp2;
            temp2 = temp2->next;
            tempC = tempC->next;
        }
    }
    else{
        tempC->next = temp1;
        temp1 = temp1->next;
        tempC = tempC->next;
    }
    return c->next;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head1 == nullptr) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head2 == nullptr) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends