/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
     Node *reverseList(Node* head)
    {
        Node *curr = head, *prev = nullptr;
        while(curr)
        {
            Node *newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        return prev;
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        num1 = reverseList(num1);
        num2 = reverseList(num2);
        Node* res = new Node(0);
        Node* curr = res;
        int carry = 0;
        while(num1 || num2 || carry)
        {
            int sum = carry;
            if(num1)
            {
                sum += num1->data;
                num1 = num1->next;
            }
            if(num2)
            {
                sum += num2->data;
                num2 = num2->next;
            }
            carry = sum / 10;
            int digit = sum % 10;
            curr->next = new Node(digit);
            curr = curr->next;
        }
        Node *ans = reverseList(res->next);
        while(ans && ans->data == 0) ans = ans->next;
        return ans;
    }
};
