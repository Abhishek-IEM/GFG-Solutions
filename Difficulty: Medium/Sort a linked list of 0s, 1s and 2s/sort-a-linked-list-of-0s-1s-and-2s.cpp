
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        Node *curr = head;
        int zero = 0, one = 0, two = 0;
        while(curr)
        {
            if(curr->data == 0) zero++;
            else if(curr->data == 1) one++;
            else two++;
            
            curr = curr->next;
        }
        curr = head;
        
        while(zero--)
        {
            curr->data = 0;
            curr = curr->next;
        }
        while(one--)
        {
            curr->data = 1;
            curr = curr->next;
        }
        while(two--)
        {
            curr->data = 2;
            curr = curr->next;
        }
        return head;
    }
};



