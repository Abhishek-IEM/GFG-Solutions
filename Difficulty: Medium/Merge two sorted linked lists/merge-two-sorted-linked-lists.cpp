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

