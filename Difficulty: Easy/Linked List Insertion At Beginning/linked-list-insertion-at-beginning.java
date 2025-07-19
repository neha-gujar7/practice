// User function Template for Java

class Solution {
    public Node insertAtBegining(Node head, int x) {
        // Code here
        Node temp=new Node(x);
       
        temp.next=head;
        return temp;
    }
}