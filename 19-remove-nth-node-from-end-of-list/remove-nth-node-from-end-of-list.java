/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {

        ListNode temp=head;
        int len=0;
        while(temp!=null){
            len++;
            temp=temp.next;
        }

        int c=len-n+1;

        if(c==1){
            head=head.next;
            return head;
        }
      

        int count=0;
        ListNode  curr=head;
        ListNode prev=null;
        while(curr!=null){
            count++;
            if(count==c){
                prev.next=curr.next;
                break;
            }
            prev=curr;
            curr=curr.next;
        }



        return head;

    }
}