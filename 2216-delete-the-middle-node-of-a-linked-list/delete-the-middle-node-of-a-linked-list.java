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
    public ListNode deleteMiddle(ListNode head) {
        if (head == null || head.next == null) return null;
        ListNode temp=head;
        // int len=0;
        // while(temp!=null){
        //     len++;
        //     temp=temp.next;
        // }

        // int mid=(len/2);
        // temp=head;
        // ListNode prev=null;
        // while(temp!=null && mid>0){
        //     mid--;
        //     prev=temp;
        //     temp=temp.next;
        // }
        // prev.next=temp.next;
        // // head=temp;
        // return head;


        //by slow fast 
        ListNode slow=head;
        ListNode fast=head;
        ListNode prev=head;
        while(fast!=null && fast.next!=null ){
            prev=slow;
            fast=fast.next.next;
            slow=slow.next;

        }
        prev.next=slow.next;
        return head;
    }
}