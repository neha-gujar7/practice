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
import java.util.Stack;
class Solution {
    public ListNode reverseList(ListNode head) {
        // not a optimal 

        // // ListNode stack<int> st;
        // Stack<Integer> st=new Stack<>();
        // ListNode temp=head;
        // while(temp!=null){
        //     st.push(temp.val);
        //     temp=temp.next;
        // }

        // temp=head;
        
        // while(temp!=null){
        //     temp.val=st.pop();
        //     temp=temp.next;
        // }
        // // temp.next=null;
        // // head=temp;
        // return head;

        // optimal
        if(head==null) return head;
        ListNode temp=head;
        ListNode prev=null;
        
        while(temp!=null){
            ListNode front=temp.next;
            temp.next=prev;
            prev=temp;
            temp=front;
        }
        return prev;

        

    }
}