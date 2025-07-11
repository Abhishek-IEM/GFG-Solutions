/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node *NN = new Node(data), *temp = head;
        
        if(head->data > data)
        {
            NN->next = head;
            while(temp->next != head) temp = temp->next;
            temp->next = NN;
            return NN;
        }
        
        while(temp->next != head && temp->next->data <= data) temp = temp->next;
        NN->next = temp->next;
        temp->next = NN;
        return head;
    }
};