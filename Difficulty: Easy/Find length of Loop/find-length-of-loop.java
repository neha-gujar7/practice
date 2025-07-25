/*
class Node
{
    int data;
    Node next;
    Node(int d) {data = d; next = null; }
}
*/

class Solution {
    // Function to find the length of a loop in the linked list.
    public int countNodesinLoop(Node head) {
        // code here.
        int count=1;
        Node temp=head;
        Node fast=head;
        Node slow=head;
        while(fast!=null && fast.next!=null){
            fast=fast.next.next;
            slow=slow.next;
            
            if(slow==fast){
                slow=slow.next;
                while(slow!=fast){
                    count++;
                     slow=slow.next;
                }
                return count;
            }
        }
        return 0;
    }
}