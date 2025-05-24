/*

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
    Node* rotate(Node* head, int k) {
        // Your code here
        if(head == NULL || head->next == NULL) return head;
        Node* temp = head;
        Node* tail = NULL;
        int n = 0;
        while(temp != NULL)
        {
            if(temp->next == NULL) tail = temp;
            n++;
            temp = temp->next;
        }
        k = k % n;
        if(k == 0) return head;
        temp = head;
        for(int i=1;i<k;i++)
        {
            temp = temp->next;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};