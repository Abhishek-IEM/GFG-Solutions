/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        if(!head) return NULL;
        
        int n = 0;
        Node* temp = head;
        
        while(temp)
        {
            n++;
            temp = temp->next;
        }
        
        if(k > n) return head;
        if(2*k - 1 == n) return head;
        
        Node* temp1 = head;
        for(int i = 1; i < k; i++) temp1 = temp1->next;
        
        Node* temp2 = head;
        for(int i = 1; i <= n - k; i++) temp2 = temp2->next;
        
        int tempData = temp1->data;
        temp1->data = temp2->data;
        temp2->data = tempData;
        
        return head;
    }
};