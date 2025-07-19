/* Node of a linked list
 class Node {
   int data;
    Node next;
    Node(int d)  { data = d;  next = null; }
}
*/

class Solution {
    int getMiddle(Node head) {
        // Your code here.
        Node temp=head;
        Node fast=head;
        Node slow=head;
        
        while(fast!=null && fast.next!=null){
            slow=temp.next;
            fast=fast.next.next;
            temp=temp.next;
        }
        return slow.data;
    }
}