/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
         Node *headCopy = new Node(0);
        Node *tailCopy = headCopy;
        Node *temp = head;
        
        while(temp)
        {
            tailCopy->next = new Node(temp->data);
            tailCopy = tailCopy->next;
            temp = temp->next;
        }
        
        tailCopy = headCopy;
        headCopy = headCopy->next;
        delete tailCopy;
        
        tailCopy = headCopy;
        temp = head;
        
        unordered_map<Node*, Node*> m;
        
        while(temp)
        {
            m[temp] = tailCopy;
            temp = temp->next;
            tailCopy = tailCopy->next;
        }
        
        tailCopy = headCopy;
        temp = head;
        while(temp)
        {
            tailCopy->random = m[temp->random];
            tailCopy = tailCopy->next;
            temp = temp->next;
        }
        return headCopy;
    }
};