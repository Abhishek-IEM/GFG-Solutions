/* node class of the linked list

class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

*/

class Solution {
    // Function to pairwise swap elements of a linked list.
    // It should returns head of the modified list
    public Node pairwiseSwap(Node head) {
        // code here
        if(head == null || head.next == null) return head;
        Node first = head, prev = null;
        while(first != null && first.next != null)
        {
            Node second = first.next;
            first.next = second.next;
            second.next = first;
            if(prev == null) head =second;
            else prev.next = second;
            prev = first;
            first = first.next;
        }
        
        return head;
    }
}